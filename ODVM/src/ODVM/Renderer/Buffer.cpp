#include "odvmpch.h"
#include "Buffer.h"

#include "ODVM/Core/Core.h"

#include "Platform/OpenGl/OpenGLBuffer.h"
#include "Renderer.h"

namespace ODVM
{

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: ODVM_CORE_ASSERT(false, "RendererAPI::API::None is not supported"); return nullptr;

		case RendererAPI::API::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}

		ODVM_CORE_ERROR("Unknown API");		
		return nullptr;

	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:	ODVM_CORE_ERROR("RendererAPI::None is not supported"); return nullptr;

			case RendererAPI::API::OpenGL: return new OpenGLIndexBuffer(indices, size);
		}

		ODVM_CORE_ERROR(false, "Unknown API");
		return nullptr;

	}

}