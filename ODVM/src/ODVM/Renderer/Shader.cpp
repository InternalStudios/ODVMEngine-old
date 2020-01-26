#include "odvmpch.h"
#include "Shader.h"
#include "Renderer.h"

#include "Platform/OpenGl/OpenGLShader.h"

namespace ODVM
{
	Shader* Shader::Create(std::string vertexSrc, std::string pixelSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: ODVM_CORE_ASSERT(false, "RendererAPI::API::None is not supported"); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLShader(vertexSrc, pixelSrc);
		}

		ODVM_CORE_ERROR("Unknown API");
		return nullptr;
	}
}
