#pragma once

#include "ODVM/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace ODVM
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

		virtual void Shutdown() override {}

	private:
		GLFWwindow* m_WindowHandle;
	};
}