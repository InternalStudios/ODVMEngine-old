#include "odvmpch.h"
#include "VertexArray.hpp"

#include "Platform/OpenGl/OpenGLVertexArray.hpp"

#include "Renderer.hpp"

namespace ODVM
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: ODVM_CORE_ASSERT(false, "RendererAPI::API::None is not supported"); return nullptr;
			case RendererAPI::API::OpenGL: return std::make_shared<OpenGLVertexArray>();
		}

		ODVM_CORE_ERROR("Unknown API");
		return nullptr;

	}
}

