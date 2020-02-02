#pragma once

#include <string.h>

#include <glm/glm.hpp>

namespace ODVM
{

	class Shader
	{
	public:
		virtual ~Shader() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static Shader* Create(std::string vertexSrc, std::string pixelSrc);

		virtual void UploadUniformMat4(const std::string& name, const glm::mat4& mat4) = 0;
	};

}