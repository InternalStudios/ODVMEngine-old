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
		case ODVM::RendererAPI::None: ODVM_CORE_ERROR("RendererAPI::None is not supported"); return nullptr;
		case ODVM::RendererAPI::OpenGL: return new OpenGLShader(vertexSrc, pixelSrc);
		}

		ODVM_CORE_ERROR("Unknown API");
		return nullptr;
	}
}
