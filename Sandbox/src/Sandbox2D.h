#pragma once

#include <ODVM.h>

#include <imgui.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


class Sandbox2D : public ODVM::Layer
{
public:
	Sandbox2D();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate(ODVM::Timestep ts) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(ODVM::Event& event) override;

private:
	ODVM::OrthographicCameraController m_CameraController;

	// Temp
	ODVM::Ref<ODVM::Shader> m_Shader;
	ODVM::Ref<ODVM::Texture2D> m_Texture;
	ODVM::Ref<ODVM::Texture2D> m_TextureLogo;
	ODVM::Ref<ODVM::VertexArray> m_VertexArray;
	glm::vec4 m_Color = { 1.0f, 0.0f, 1.0f, 1.0f };

	bool m_ColorOpen = false;
};