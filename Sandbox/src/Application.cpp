#include <ODVM.h>

#include <sstream>

#include <glm/gtc/type_ptr.hpp>

#include "imgui.h"

class ExampleLayer : public ODVM::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f), m_CameraRotation(0.0f)
	{

		color.r = 0.0f, color.g = 0.5f, color.b = 1.0f, color.a = 1.0f;

		m_VertexArray.reset(ODVM::VertexArray::Create());

		float vertices[4 * 7] = {
			-0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f
		};
		ODVM::Ref<ODVM::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(ODVM::VertexBuffer::Create(vertices, sizeof(vertices)));

		ODVM::BufferLayout layout = {
			{ODVM::ShaderDataType::Float3, "a_Position"},
			{ODVM::ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[4] = { 0, 1, 2, 3 };
		ODVM::Ref<ODVM::IndexBuffer> indexBuffer;
		indexBuffer.reset(ODVM::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);



		m_SquareVA.reset(ODVM::VertexArray::Create());
		float squareVertices[4 * 5] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.0f, 0.0f, 1.0f
		};


		ODVM::Ref<ODVM::VertexBuffer> squareVB;
		squareVB.reset(ODVM::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));


		ODVM::BufferLayout squareLayout = {
			{ODVM::ShaderDataType::Float3, "a_Position"},
			{ODVM::ShaderDataType::Float2, "a_TextureCoords"}
		};
		squareVB->SetLayout(squareLayout);
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[4] = { 0, 1, 2, 3 };
		ODVM::Ref<ODVM::IndexBuffer> squareIB;
		squareIB.reset(ODVM::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		m_FlatColorShader = ODVM::Shader::Create("assets/shaders/FlatColor.glsl");

		m_TextureShader = ODVM::Shader::Create("assets/shaders/Texture.glsl");

		m_Checkerboard = ODVM::Texture2D::Create("assets/textures/Checkerboard.png");
		m_Logo = ODVM::Texture2D::Create("assets/textures/ChernoLogo.png");
		m_TextureShader->Bind();
		m_TextureShader->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(ODVM::Timestep ts) override
	{
		float fps = 0;
		if(ts.getSeconds() != 0)
			fps = 1 / ts.getSeconds();
		

		std::stringstream ss;
		ss << ODVM::Application::Get().GetWindow().GetTitle() << " FPS: " << (int)fps << " Camera Coords: X:" << m_CameraPosition.x << ", Y: " << m_CameraPosition.y << ", Z: " << m_CameraPosition.z;
		ODVM::Application::Get().GetWindow().SetTitle(ss.str().c_str());



		if (ODVM::Input::IsKeyPressed(ODVM_KEY_W))
		{
			m_CameraPosition.y += m_CameraSpeed * ts;
		}
		if (ODVM::Input::IsKeyPressed(ODVM_KEY_S))
		{
			m_CameraPosition.y -= m_CameraSpeed * ts;
		}
		if (ODVM::Input::IsKeyPressed(ODVM_KEY_A))
			m_CameraPosition.x -= m_CameraSpeed * ts;
		
		if (ODVM::Input::IsKeyPressed(ODVM_KEY_D))
			m_CameraPosition.x += m_CameraSpeed * ts;

		if (ODVM::Input::IsKeyPressed(ODVM_KEY_Q))
		{
			m_CameraRotation.z += m_CameraRotationSpeed * ts;
			if (m_CameraRotation.z == 360.0f)
				m_CameraRotation.z = 0.0f;

			if (m_CameraRotation.z == 0.0f)
				m_CameraRotation.z = 360.0f;
		}
		if (ODVM::Input::IsKeyPressed(ODVM_KEY_E))
		{
			m_CameraRotation.z -= m_CameraRotationSpeed * ts;

		}


		ODVM::RenderCommand::SetClearColor({ 0.2f, 0.2f, 0.2f, 1.0f });
		ODVM::RenderCommand::Clear();

		glm::vec4 redColor(0.8f, 0.1f, 0.1f, 1.0f);
		glm::vec4 magentaColor(1.0f, 0.0f, 1.0f, 1.0f);
		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		ODVM::Renderer::BeginScene(m_Camera);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f , y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
				
				
				if ((x + y) % 2 == 0)
				{
					m_FlatColorShader->UploadUniformFloat4("u_Color", magentaColor);
				}
				else
				{
					m_FlatColorShader->UploadUniformFloat4("u_Color", color);
				}
				
				ODVM::Renderer::Submit(m_SquareVA, m_FlatColorShader, transform);

			}

		}
		
		m_Checkerboard->Bind();
		ODVM::Renderer::Submit(m_SquareVA, m_TextureShader, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_Logo->Bind();
		ODVM::Renderer::Submit(m_SquareVA, m_TextureShader, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		ODVM::Renderer::EndScene();

	}

	virtual void OnImGuiRender()
	{
		ImGui::Begin("Settings", (bool*)1, (ImGuiWindowFlags)ImGuiWindowFlags_MenuBar);
		if (ImGui::BeginMenuBar())
		{
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

	void OnEvent(ODVM::Event& event) override
	{

	}


private:

	ODVM::Ref<ODVM::Shader> m_FlatColorShader;
	ODVM::Ref<ODVM::Shader> m_TextureShader;

	ODVM::Ref<ODVM::VertexArray> m_VertexArray;

	ODVM::Ref<ODVM::VertexArray> m_SquareVA;

	ODVM::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	glm::vec3 m_CameraRotation;
	float m_CameraSpeed = 2.0f;
	float m_CameraRotationSpeed = 180.0f;
	glm::vec4 color;

	bool ImGuiOpen = true;

	bool selected = false;

	ODVM::Ref<ODVM::Texture2D> m_Checkerboard, m_Logo;


};

class Sandbox : public ODVM::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		Application::Get().GetWindow().SetVSync(false);
	}

	~Sandbox()
	{

	}

	
};

ODVM::Application* ODVM::CreateApplication()
{
	return new Sandbox();
}