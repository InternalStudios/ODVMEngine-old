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

		virtual void UploadUniformMat4(const std::string& name, const glm::mat4& mat4);
	private:
		uint32_t m_RendererID;

	};
}
