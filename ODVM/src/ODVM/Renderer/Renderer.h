#pragma once

#include "Buffer.h"
#include "VertexArray.h"
#include "Shader.h"

namespace ODVM
{
	enum class RendererAPI
	{
		None = 0, OpenGL = 1
	};

	class Renderer
	{
	public:
		inline static RendererAPI GetAPI() { return s_RendererAPI; }

		inline static Shader* CreateShader(std::string vertexSrc, std::string pixelSrc) { return Shader::Create(vertexSrc, pixelSrc); }
		inline static VertexBuffer* CreateVertexBuffer(float* vertices, uint32_t size) { return VertexBuffer::Create(vertices, size); }
		inline static IndexBuffer* CreateIndexBuffer(uint32_t* indices, uint32_t count) { return IndexBuffer::Create(indices, count); }
	private:

		static RendererAPI s_RendererAPI;

	};

}