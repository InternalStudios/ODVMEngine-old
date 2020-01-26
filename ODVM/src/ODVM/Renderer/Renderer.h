#pragma once

#include "Buffer.h"
#include "VertexArray.h"
#include "Shader.h"

#include "RendererAPI.h"

namespace ODVM
{

	class Renderer
	{
	public:
		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);


		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};

}