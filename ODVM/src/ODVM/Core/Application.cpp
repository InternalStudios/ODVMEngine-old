#include <odvmpch.h>
#include "Application.hpp"

#include "Log.hpp"

#include "Input.hpp"

#include <glm/glm.hpp>

#include "ODVM/Renderer/RenderCommand.hpp"

namespace ODVM
{

	Application* Application::s_Instance = nullptr;



	Application::Application()
	{
		ODVM_PROFILE_FUNCTION();

		#ifdef ODVM_PLATFORM_WINDOWS
		ODVM_CORE_INFO("Platform: Windows (x64)");
		#endif
		ODVM_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		
		m_Window = Scope<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
		
		Renderer::Init();
		
		
		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);


	}



	Application::~Application()
	{
		ODVM_PROFILE_FUNCTION();

		Renderer::Shutdown();
	}

/*

    void Application::InitDiscord()
    {
        auto result = discord::Core::Create(687948082150768665, DiscordCreateFlags_Default, &m_Core);
        discord::Activity activity{};
        activity.SetState("Making");
        m_Core->ActivityManager().UpdateActivity(activity, [](discord::Result result){});
        
    }

    void Application::UpdateDiscord()
    {
        
    }*/

	void Application::PushLayer(Layer* layer)
	{
		ODVM_PROFILE_FUNCTION();

		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		ODVM_PROFILE_FUNCTION();

		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		ODVM_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::run()
	{
		while (m_Running)
		{
			ODVM_PROFILE_SCOPE("void Application::run(void)");

			Timestep timestep;

			if (!m_Minimized)
			{
				{
					ODVM_PROFILE_SCOPE("Layer Update Application::run()");
					for (Layer* layer : m_LayerStack)
						layer->OnUpdate(timestep);
				}
			}

			m_ImGuiLayer->Begin();
			{
				ODVM_PROFILE_SCOPE("Layer OnImguiRender Application::run()");

				for (Layer* layer : m_LayerStack)
					layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		ODVM_PROFILE_FUNCTION();

		if (e.GetHeight() == 0 || e.GetWidth() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;

		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}
}
