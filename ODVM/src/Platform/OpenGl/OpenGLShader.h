#pragma once
#include "ODVM/Renderer/Shader.h"

namespace ODVM
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		virtual void Bind() const;
		virtual void Unbind() const;

		virtual void UploadUniformInt(const std::string& name, int value) override;
		virtual void UploadUniformFloat(const std::string& name, float value) override;
		virtual void UploadUniformFloat2(const std::string& name, const glm::vec2& vec2) override;
		virtual void UploadUniformFloat3(const std::string& name, const glm::vec3& vec3) override;
		virtual void UploadUniformMat3(const std::string& name, const glm::mat3& mat3) override;
		virtual void UploadUniformFloat4(const std::string& name, const glm::vec4& vec4);
		virtual void UploadUniformMat4(const std::string& name, const glm::mat4& mat4);








	private:
		uint32_t m_RendererID;

	};
}
