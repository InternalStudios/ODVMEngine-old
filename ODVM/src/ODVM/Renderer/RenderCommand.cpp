#include "odvmpch.h"

#include "ODVM/Renderer/Renderer.h"

#include "RenderCommand.h"

#include "Platform/OpenGl/OpenGLRendererAPI.h"

namespace ODVM
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = CreateScope<OpenGLRendererAPI>();
	


}

