 #include "Sandbox3D.hpp"

#include <string>


Sandbox3D::Sandbox3D()
	: Layer("Sandbox2D"), m_CameraController((float)ODVM::Application::Get().GetWindow().GetWidth() / (float)ODVM::Application::Get().GetWindow().GetHeight())
{
	texture = ODVM::Texture2D::Create("assets/textures/Checkerboard.png");
	path = "assets/textures/cube.obj";
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
	ss << ODVM::Application::Get().GetWindow().GetTitle() << " FPS: " << (int)fps << " Camera Coords: X:" << m_CameraController.GetCamera().GetPosition().x << ", Y: " << m_CameraController.GetCamera().GetPosition().y << ", Z: " << m_CameraController.GetCamera().GetPosition().z;
	ODVM::Application::Get().GetWindow().SetTitle(ss.str().c_str());

    m_CameraController.OnUpdate(ts);

	ODVM::RenderCommand::SetClearColor({1.0f, 0.0f, 1.0f, 1.0f});
	ODVM::RenderCommand::Clear();

	ODVM::Renderer3D::BeginScene(m_CameraController.GetCamera());
	//ODVM::Renderer2D::DrawQuad({0.5f, 0.2f}, glm::vec2(1.0f, 1.0f), m_TextureLogo);
	//ODVM::Renderer2D::DrawQuad({0.0f, 0.0f, -0.1f}, glm::vec2(20.0f, 20.0f), m_Texture, 20.0f);
	//ODVM::Renderer2D::DrawRotatedQuad({-0.5f, 0.2f}, glm::vec2(1.0f, 2.0f), glm::radians(45.0f), m_Color);
    //ODVM::Renderer3D::DrawCube({0.0f, 0.0f, 0.0f}, texture);
    //ODVM::Renderer3D::DrawCube({10.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f, 1.0f});
	ODVM::Renderer3D::DrawModel({10.0f, 0.0f, 0.0f}, path, {1.0f, 1.0f, 1.0f, 1.0f});
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
	m_CameraController.OnEvent(e);
}
