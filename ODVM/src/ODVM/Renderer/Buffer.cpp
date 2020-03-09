#include "odvmpch.h"
#include "Buffer.hpp"

#include "ODVM/Core/Core.hpp"

#include "Platform/OpenGl/OpenGLBuffer.hpp"
#include "Renderer.hpp"

namespace ODVM
{

	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: ODVM_CORE_ASSERT(false, "RendererAPI::API::None is not supported"); return nullptr;

		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLVertexBuffer>(vertices, size);
		}

		ODVM_CORE_ERROR("Unknown API");		
		return nullptr;

	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:	ODVM_CORE_ERROR("RendererAPI::None is not supported"); return nullptr;

			case RendererAPI::API::OpenGL: return std::make_shared<OpenGLIndexBuffer>(indices, size);
		}

		ODVM_CORE_ERROR("Unknown API");
		return nullptr;

	}

}
