#pragma once

#include "Buffer.h"
#include "VertexArray.h"
#include "Shader.h"

#include "Cameras.h"

#include "RendererAPI.h"

#include <glm/glm.hpp>

namespace ODVM
{

	class Renderer
	{
	public:
		static void Init();

		static void BeginScene(Camera& camera);
		static void EndScene();

		static void Submit(const Ref<VertexArray>& vertexArray, const Ref<Shader>& shader, const glm::mat4& transform = glm::mat4(1.0f));


		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};
		static SceneData* m_SceneData;
	};

}