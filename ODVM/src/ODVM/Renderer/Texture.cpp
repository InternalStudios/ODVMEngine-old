#include "odvmpch.h"
#include "Texture.hpp"

#include <string.h>

#include "Renderer.hpp"
#include "Platform/OpenGl/OpenGLTexture.hpp"

namespace ODVM
{

	Ref<ODVM::Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: ODVM_CORE_ASSERT(false, "RendererAPI::API::None is not supported"); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLTexture2D>(path);
		}

		ODVM_CORE_ERROR("Unknown API");
		return nullptr;
	}

	Ref<ODVM::Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: ODVM_CORE_ASSERT(false, "RendererAPI::API::None is not supported"); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLTexture2D>(width, height);
		}

		ODVM_CORE_ERROR("Unknown API");
		return nullptr;
	}

}

