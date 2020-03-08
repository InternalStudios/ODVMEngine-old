#include "odvmpch.h"

#include "ODVM/Renderer/Renderer.hpp"

#include "RenderCommand.hpp"

#include "Platform/OpenGl/OpenGLRendererAPI.hpp"

namespace ODVM
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = CreateScope<OpenGLRendererAPI>();
	


}

