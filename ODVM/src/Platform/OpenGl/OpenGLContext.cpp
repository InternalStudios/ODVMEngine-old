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

		#ifdef ODVM_ENABLE_ASSERTS
			int versionMajor;
			int versionMinor;
			glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
			glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

			ODVM_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "ODVM Engine only supports OpenGL versions 4.5 or higher!");
		#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}