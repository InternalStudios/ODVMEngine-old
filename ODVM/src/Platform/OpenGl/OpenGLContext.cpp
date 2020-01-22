#include "odvmpch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace ODVM
{

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		ODVM_CORE_ASSERT(windowHandle, " Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ODVM_CORE_ASSERT(status, "Failed to initialize Glad!");

		ODVM_CORE_INFO("OpenGL Info: ");
		ODVM_CORE_INFO("  Vendor: {0},", glGetString(GL_VENDOR));
		ODVM_CORE_INFO("  Renderer: {0},", glGetString(GL_RENDERER));
		ODVM_CORE_INFO("  Version: {0},", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}