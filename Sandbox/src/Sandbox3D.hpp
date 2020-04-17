#pragma once

#include <ODVM.h>

#include <imgui.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


class Sandbox3D : public ODVM::Layer
{
public:
	Sandbox3D();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate(ODVM::Timestep ts) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(ODVM::Event& event) override;

private:
	ODVM::Ref<ODVM::PerspectiveCamera> m_Camera;

	// Temp
};