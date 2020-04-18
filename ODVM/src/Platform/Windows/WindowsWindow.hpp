#pragma once

#include "ODVM/Core/Window.hpp"

#include "ODVM/Renderer/GraphicsContext.hpp"

#include "GLFW/glfw3.h"

namespace ODVM
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;

		virtual inline unsigned int GetWidth() const override { return m_Data.Width; }
		virtual inline unsigned int GetHeight() const override { return m_Data.Height; }
		//Window attributes
		virtual inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const override { return m_Window; }

		virtual void SetTitle(const char* title) override;


		virtual std::string GetTitle() const override;

	private:
		inline static double previousTime = glfwGetTime();
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;
		Scope<GraphicsContext> m_Context;


		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			bool m_Focused;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}


