#include <ODVM.h>

#include "imgui.h"

class ExampleLayer : public ODVM::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		if (ODVM::Input::IsKeyPressed(ODVM_KEY_TAB))
			ODVM_TRACE("Tab was pressed");



	}

	virtual void OnImGuiRender()
	{
		bool close = true;
		ImGui::Begin("Test", &close);
		ImGui::Text("Hello");
		ImGui::End();

	}

	void OnEvent(ODVM::Event& event) override
	{
		//ODVM_TRACE("{0}", event);
	}
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