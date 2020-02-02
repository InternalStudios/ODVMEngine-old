#include <ODVM.h>

#include <sstream>

#include "imgui.h"

class ExampleLayer : public ODVM::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f), m_CameraRotation(0.0f)
	{

		m_VertexArray.reset(ODVM::VertexArray::Create());

		float vertices[4 * 7] = {
			-0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f
		};
		std::shared_ptr<ODVM::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(ODVM::VertexBuffer::Create(vertices, sizeof(vertices)));

		ODVM::BufferLayout layout = {
			{ODVM::ShaderDataType::Float3, "a_Position"},
			{ODVM::ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[4] = { 0, 1, 2, 3 };
		std::shared_ptr<ODVM::IndexBuffer> indexBuffer;
		indexBuffer.reset(ODVM::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);



		m_SquareVA.reset(ODVM::VertexArray::Create());
		float squareVertices[4 * 3] = {
			0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 1.0, 0.0f
		};


		std::shared_ptr<ODVM::VertexBuffer> squareVB;
		squareVB.reset(ODVM::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));


		ODVM::BufferLayout squareLayout = {
			{ODVM::ShaderDataType::Float3, "a_Position"}
		};
		squareVB->SetLayout(squareLayout);
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[4] = { 0, 1, 2, 3 };
		std::shared_ptr<ODVM::IndexBuffer> squareIB;
		squareIB.reset(ODVM::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);


		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;


			out vec3 v_Position;
			out vec4 v_Color;
	
			void main()
			{
				v_Color = a_Color;
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = v_Color;
			}
)";

		m_Shader.reset(ODVM::Shader::Create(vertexSrc, fragmentSrc));

		std::string vertexSrc2 = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;
	
			void main()
			{
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
				v_Color = vec4(1.0, 0.0, 1.0, 0.5);
			}
		)";

		std::string fragmentSrc2 = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			
			in vec4 v_Color;

			void main()
			{
				color = v_Color;
			}
)";

		m_Shader2.reset(ODVM::Shader::Create(vertexSrc2, fragmentSrc2));

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



		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);


		ODVM::Renderer::BeginScene(m_Camera);

		glm::vec4 redColor(0.8f, 0.3f, 0.2f, 1.0f);
		glm::vec4 blueColor(0.2f, 0.3f, 0.8f, 1.0f);

		ODVM::Renderer::Submit(m_SquareVA, m_Shader2);
		ODVM::Renderer::Submit(m_VertexArray, m_Shader);
		ODVM::Renderer::EndScene();

	}

	virtual void OnImGuiRender()
	{


	}

	void OnEvent(ODVM::Event& event) override
	{

	}


private:
	std::shared_ptr<ODVM::Shader> m_Shader;
	std::shared_ptr<ODVM::VertexArray> m_VertexArray;

	std::shared_ptr<ODVM::Shader> m_Shader2;
	std::shared_ptr<ODVM::VertexArray> m_SquareVA;

	ODVM::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	glm::vec3 m_CameraRotation;
	float m_CameraSpeed = 2.0f;
	float m_CameraRotationSpeed = 180.0f;



};

class Sandbox : public ODVM::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

	
};

ODVM::Application* ODVM::CreateApplication()
{
	return new Sandbox();
}