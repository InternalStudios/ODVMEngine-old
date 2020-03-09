#include <ODVM.h>
#include <ODVM/Core/EntryPoint.hpp>

#include <sstream>

#include <glm/gtc/type_ptr.hpp>

#include "imgui.h"

#include "Sandbox2D.hpp"
#include "VulkanLayer.hpp"

class ExampleLayer : public ODVM::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_CameraController((float)ODVM::Application::Get().GetWindow().GetWidth() / (float)ODVM::Application::Get().GetWindow().GetHeight(), true)
	{
		
		color.r = 0.0f, color.g = 0.5f, color.b = 1.0f, color.a = 1.0f;

		m_VertexArray = ODVM::VertexArray::Create();

		float vertices[4 * 7] = {
			-0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f
		};
		ODVM::Ref<ODVM::VertexBuffer> vertexBuffer;
		vertexBuffer = ODVM::VertexBuffer::Create(vertices, sizeof(vertices));

		ODVM::BufferLayout layout = {
			{ODVM::ShaderDataType::Float3, "a_Position"},
			{ODVM::ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[4] = { 0, 1, 2, 3 };
		ODVM::Ref<ODVM::IndexBuffer> indexBuffer;
		indexBuffer = ODVM::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
		m_VertexArray->SetIndexBuffer(indexBuffer);



		m_SquareVA = ODVM::VertexArray::Create();
		float squareVertices[4 * 5] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.0f, 0.0f, 1.0f
		};


		ODVM::Ref<ODVM::VertexBuffer> squareVB;
		squareVB = ODVM::VertexBuffer::Create(squareVertices, sizeof(squareVertices));


		ODVM::BufferLayout squareLayout = {
			{ODVM::ShaderDataType::Float3, "a_Position"},
			{ODVM::ShaderDataType::Float2, "a_TextureCoords"}
		};
		squareVB->SetLayout(squareLayout);
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[4] = { 0, 1, 2, 3 };
		ODVM::Ref<ODVM::IndexBuffer> squareIB;
		squareIB = ODVM::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
		m_SquareVA->SetIndexBuffer(squareIB);

		ODVM::Ref<ODVM::Shader> flatColorShader = m_Library.Load("assets/shaders/FlatColor.glsl");

		ODVM::Ref<ODVM::Shader> textureShader = m_Library.Load("assets/shaders/Texture.glsl");

		m_Checkerboard = ODVM::Texture2D::Create("assets/textures/Checkerboard.png");
		m_Logo = ODVM::Texture2D::Create("assets/textures/ChernoLogo.png");
		textureShader->Bind();
		textureShader->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(ODVM::Timestep ts) override
	{
		float fps = 0;
		if(ts.getSeconds() != 0)
			fps = 1 / ts.getSeconds();
		

		std::stringstream ss;
		ss << ODVM::Application::Get().GetWindow().GetTitle() << " FPS: " << (int)fps << " Camera Coords: X:" << m_CameraController.GetPosition().x << ", Y: " << m_CameraController.GetPosition().y << ", Z: " << m_CameraController.GetPosition().z;
		ODVM::Application::Get().GetWindow().SetTitle(ss.str().c_str());

		m_CameraController.OnUpdate(ts);

		ODVM::RenderCommand::SetClearColor({ 0.2f, 0.2f, 0.2f, 1.0f });
		ODVM::RenderCommand::Clear();

		glm::vec4 redColor(0.8f, 0.1f, 0.1f, 1.0f);
		glm::vec4 magentaColor(1.0f, 0.0f, 1.0f, 1.0f);

		ODVM::Renderer::BeginScene(m_CameraController.GetCamera());

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f , y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
				
				
				if ((x + y) % 2 == 0)
				{
					m_Library.GetShader("FlatColor")->UploadUniformFloat4("u_Color", magentaColor);
				}
				else
				{
					m_Library.GetShader("FlatColor")->UploadUniformFloat4("u_Color", color);
				}
				
				ODVM::Renderer::Submit(m_SquareVA, m_Library.GetShader("FlatColor"), transform);

			}

		}
		
		m_Checkerboard->Bind();
		ODVM::Renderer::Submit(m_SquareVA, m_Library.GetShader("Texture"), glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		if (texture)
		{
			m_Logo->Bind();
			ODVM::Renderer::Submit(m_SquareVA, m_Library.GetShader("Texture"), glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		}
		ODVM::Renderer::EndScene();

	}

	virtual void OnImGuiRender()
	{
		ImGui::Begin("Settings", nullptr, (ImGuiWindowFlags)ImGuiWindowFlags_MenuBar);
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				ImGui::MenuItem("Logo", NULL, &texture);
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Windows"))
			{
				ImGui::MenuItem("Color", NULL, &ImGuiOpen);
				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}
		ImGui::End();

		if(ImGuiOpen == true)
		{
			ImGuiWindowFlags window_flags = 0;
			window_flags |= ImGuiWindowFlags_MenuBar;
			ImGui::Begin("Color", &ImGuiOpen, window_flags);
			ImGui::ColorEdit4("Color", glm::value_ptr(color));
			ImGui::End();
		}
		else
		{
			color.r = 0.0f, color.g = 0.5f, color.b = 1.0f, color.a = 1.0f;
		}



	}

	void OnEvent(ODVM::Event& e) override
	{
		m_CameraController.OnEvent(e);


	}


private:

	ODVM::ShaderLibrary m_Library;

	ODVM::Ref<ODVM::VertexArray> m_VertexArray;

	ODVM::Ref<ODVM::VertexArray> m_SquareVA;

	glm::vec4 color;

	bool ImGuiOpen = true;

	bool texture;

	bool selected = false;

	ODVM::Ref<ODVM::Texture2D> m_Checkerboard, m_Logo;

	ODVM::OrthographicCameraController m_CameraController;
};

class Sandbox : public ODVM::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
		//PushLayer(new VulkanLayer());
	}

	~Sandbox()
	{

	}

	
};

ODVM::Application* ODVM::CreateApplication()
{
	return new Sandbox();
}
