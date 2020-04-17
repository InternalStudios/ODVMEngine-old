#include "Sandbox3D.hpp"



Sandbox3D::Sandbox3D()
	: Layer("Sandbox2D")
{
    m_Camera = ODVM::CreateRef<ODVM::PerspectiveCamera>((float)ODVM::Application::Get().GetWindow().GetWidth() / (float)ODVM::Application::Get().GetWindow().GetHeight());
}

void Sandbox3D::OnAttach()
{
	ODVM_PROFILE_FUNCTION();

}

void Sandbox3D::OnDetach()
{
	
}

void Sandbox3D::OnUpdate(ODVM::Timestep ts)
{

	ODVM_PROFILE_FUNCTION();

	float fps = 0;
	if (ts.getSeconds() != 0)
		fps = 1 / ts.getSeconds();


	std::stringstream ss;
	ss << ODVM::Application::Get().GetWindow().GetTitle() << " FPS: " << (int)fps << " Camera Coords: X:" << m_Camera->GetPosition().x << ", Y: " << m_Camera->GetPosition().y << ", Z: " << m_Camera->GetPosition().z;
	ODVM::Application::Get().GetWindow().SetTitle(ss.str().c_str());

    m_Camera->OnUpdate();

	ODVM::RenderCommand::SetClearColor({1.0f, 0.0f, 1.0f, 1.0f});
	ODVM::RenderCommand::Clear();

	ODVM::Renderer3D::BeginScene(*m_Camera);
	//ODVM::Renderer2D::DrawQuad({0.5f, 0.2f}, glm::vec2(1.0f, 1.0f), m_TextureLogo);
	//ODVM::Renderer2D::DrawQuad({0.0f, 0.0f, -0.1f}, glm::vec2(20.0f, 20.0f), m_Texture, 20.0f);
	//ODVM::Renderer2D::DrawRotatedQuad({-0.5f, 0.2f}, glm::vec2(1.0f, 2.0f), glm::radians(45.0f), m_Color);
    ODVM::Renderer3D::DrawCube({0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f});
	ODVM::Renderer3D::EndScene();
}

void Sandbox3D::OnImGuiRender()
{
	ODVM_PROFILE_FUNCTION();
	ImGui::Begin("Settings", nullptr, (ImGuiWindowFlags)ImGuiWindowFlags_MenuBar);
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("Windows"))
		{
			ImGui::EndMenu();
		}

		ImGui::EndMenuBar();
	}
	ImGui::End();

}

void Sandbox3D::OnEvent(ODVM::Event& e)
{
}
