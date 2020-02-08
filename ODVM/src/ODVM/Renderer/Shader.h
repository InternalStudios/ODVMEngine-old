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

		virtual void UploadUniformInt(const std::string& name, int value) = 0;

		virtual void UploadUniformFloat(const std::string& name, float value) = 0;
		virtual void UploadUniformFloat2(const std::string& name, const glm::vec2& vec2) = 0;
		virtual void UploadUniformFloat3(const std::string& name, const glm::vec3& vec3) = 0;
		virtual void UploadUniformFloat4(const std::string& name, const glm::vec4& vec4) = 0;

		virtual void UploadUniformMat3(const std::string& name, const glm::mat3& mat3) = 0;
		virtual void UploadUniformMat4(const std::string& name, const glm::mat4& mat4) = 0;
	};

}