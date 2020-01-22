#pragma once

#include "Platform/Windows/WindowsInput.h"
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "ODVM/Events/ApplicationEvent.h"
#include "ODVM/LayerStack.h"

#include "ODVM/ImGui/ImGuiLayer.h"

#include "ODVM/Renderer/Shader.h"

#include "Renderer/Buffer.h"


namespace ODVM
{
	class ODVM_API Application
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

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
	private:
		static Application* s_Instance;
	};

	//To be defined in client
	Application* CreateApplication();
}
