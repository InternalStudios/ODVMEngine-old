#pragma once

#include "ODVM/Core/Platform.h"

#include <GLFW/glfw3.h>

namespace ODVM
{
	class Windows : public Platform
	{
	private:
		virtual float GetTimeImpl() override { return glfwGetTime(); }

	};
}