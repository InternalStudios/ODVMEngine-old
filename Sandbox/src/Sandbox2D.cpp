#include "Sandbox2D.hpp"



Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController((float)ODVM::Application::Get().GetWindow().GetWidth() / (float)ODVM::Application::Get().GetWindow().GetHeight())
{
}

void Sandbox2D::OnAttach()
{
	ODVM_PROFILE_FUNCTION();

	m_Color.r = 1.0f, m_Color.g = 0.0f, m_Color.b = 1.0f, m_Color.a = 1.0f;
	{
		ODVM_PROFILE_SCOPE("Checkerboard");

		m_Texture = ODVM::Texture2D::Create("./assets/textures/Checkerboard.png");
	}
	
	//m_TextureLogo = ODVM::Texture2D::Create("assets/textures/ChernoLogo.png");

}

void Sandbox2D::OnDetach()
{
	
}

void Sandbox2D::OnUpdate(ODVM::Timestep ts)
{

	ODVM_PROFILE_FUNCTION();

	float fps = 0;
	if (ts.getSeconds() != 0)
		fps = 1 / ts.getSeconds();


	std::stringstream ss;
	ss << ODVM::Application::Get().GetWindow().GetTitle() << " FPS: " << (int)fps << " Camera Coords: X:" << m_CameraController.GetPosition().x << ", Y: " << m_CameraController.GetPosition().y << ", Z: " << m_CameraController.GetPosition().z;
	ODVM::Application::Get().GetWindow().SetTitle(ss.str().c_str());

	m_CameraController.OnUpdate(ts);

	ODVM::RenderCommand::SetClearColor({1.0f, 0.0f, 1.0f, 1.0f});
	ODVM::RenderCommand::Clear();

	ODVM::Renderer2D::BeginScene(m_CameraController.GetCamera());
	//ODVM::Renderer2D::DrawQuad({0.5f, 0.2f}, glm::vec2(1.0f, 1.0f), m_TextureLogo);
	//ODVM::Renderer2D::DrawQuad({0.0f, 0.0f, -0.1f}, glm::vec2(20.0f, 20.0f), m_Texture, 20.0f);
	//ODVM::Renderer2D::DrawRotatedQuad({-0.5f, 0.2f}, glm::vec2(1.0f, 2.0f), glm::radians(45.0f), m_Color);
	ODVM::Renderer2D::DrawQuad({0.0f, 0.0f, 0.0f}, {1.0f, 1.0f}, m_Color);
	ODVM::Renderer2D::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
	ODVM_PROFILE_FUNCTION();
	ImGui::Begin("Settings", nullptr, (ImGuiWindowFlags)ImGuiWindowFlags_MenuBar);
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("Windows"))
		{
			ImGui::MenuItem("Color", NULL, &m_ColorOpen);
			ImGui::EndMenu();
		}

		ImGui::EndMenuBar();
	}
	ImGui::End();

	if (m_ColorOpen)
	{
		ImGuiWindowFlags window_flags = 0;
		window_flags |= ImGuiWindowFlags_MenuBar;
		ImGui::Begin("Color", &m_ColorOpen, window_flags);
		ImGui::ColorEdit4("Color", glm::value_ptr(m_Color));
		ImGui::End();
	}
}

void Sandbox2D::OnEvent(ODVM::Event& e)
{
	m_CameraController.OnEvent(e);
}
