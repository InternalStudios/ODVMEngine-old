#include <ODVM.h>

class ExampleLayer : public ODVM::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		//ODVM_INFO("ExampleLayer::Update");
		if (ODVM::Input::IsKeyPressed(ODVM_KEY_TAB))
			ODVM_TRACE("Tab was pressed");
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
		PushOverlay(new ODVM::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

ODVM::Application* ODVM::CreateApplication()
{
	return new Sandbox();
}