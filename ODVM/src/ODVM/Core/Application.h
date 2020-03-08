#pragma once

#include "Core.h"

#include "KeyCodes.h"

#include "Window.h"
#include "LayerStack.h"
#include "ODVM/Events/Event.h"
#include "ODVM/Events/ApplicationEvent.h"

#include "ODVM/ImGui/ImGuiLayer.h"

#include "ODVM/Renderer/VertexArray.h"
#include "ODVM/Renderer/Shader.h"
#include "ODVM/Renderer/Buffer.h"
#include "ODVM/Renderer/Renderer.h"

#include "ODVM/Core/Timesteps.h"


namespace ODVM
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

		void OnEvent(Event& e);
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }

		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		bool m_Minimized = false;


	private:
		static Application* s_Instance;
	};

	//To be defined in client
	Application* CreateApplication();
}
