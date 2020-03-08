#pragma once

#include "Core.hpp"

#include "KeyCodes.hpp"

#include "Window.hpp"
#include "LayerStack.hpp"
#include "ODVM/Events/Event.hpp"
#include "ODVM/Events/ApplicationEvent.hpp"

#include "ODVM/ImGui/ImGuiLayer.hpp"

#include "ODVM/Renderer/VertexArray.hpp"
#include "ODVM/Renderer/Shader.hpp"
#include "ODVM/Renderer/Buffer.hpp"
#include "ODVM/Renderer/Renderer.hpp"

#include "ODVM/Core/Timesteps.hpp"


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
