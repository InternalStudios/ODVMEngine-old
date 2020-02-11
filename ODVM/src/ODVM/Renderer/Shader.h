#pragma once

#include <string.h>

#include <unordered_map>

#include <glm/glm.hpp>

namespace ODVM
{

	

	class Shader
	{
	public:
		virtual ~Shader() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual std::string& GetName() = 0;

		static Ref<Shader> Create(const std::string name, const std::string vertexSrc, const std::string pixelSrc);
		static Ref<Shader> Create(const std::string path);

		virtual void UploadUniformInt(const std::string& name, int value) = 0;

		virtual void UploadUniformFloat(const std::string& name, float value) = 0;
		virtual void UploadUniformFloat2(const std::string& name, const glm::vec2& vec2) = 0;
		virtual void UploadUniformFloat3(const std::string& name, const glm::vec3& vec3) = 0;
		virtual void UploadUniformFloat4(const std::string& name, const glm::vec4& vec4) = 0;

		virtual void UploadUniformMat3(const std::string& name, const glm::mat3& mat3) = 0;
		virtual void UploadUniformMat4(const std::string& name, const glm::mat4& mat4) = 0;
	};

	class ShaderLibrary
	{
	public:
		void AddShader(const Ref<Shader>& shader);
		void AddShader(const std::string& name, const Ref<Shader>& shader);
		Ref<Shader> Load(const std::string& path);
		Ref<Shader> Load(const std::string& name, const std::string& path);

		Ref<Shader> GetShader(const std::string& name);
	private:
		std::unordered_map<std::string, Ref<Shader>> m_Shaders;
	};

}