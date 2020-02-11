#include "odvmpch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGl/OpenGLShader.h"

namespace ODVM
{
	Ref<Shader> Shader::Create(std::string name, std::string vertexSrc, std::string pixelSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: ODVM_CORE_ASSERT(false, "RendererAPI::API::None is not supported"); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLShader>(name, vertexSrc, pixelSrc);
		}

		ODVM_CORE_ERROR("Unknown API");
		return nullptr;
	}

	Ref<Shader> Shader::Create(std::string path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: ODVM_CORE_ASSERT(false, "RendererAPI::API::None is not supported"); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLShader>(path);
		}

		ODVM_CORE_ERROR("Unknown API");
		return nullptr;
	}

	void ShaderLibrary::AddShader(const Ref<Shader>& shader)
	{
		AddShader(shader->GetName(), shader);
	}

	void ShaderLibrary::AddShader(const std::string& name, const Ref<Shader>& shader)
	{
		ODVM_CORE_ASSERT(m_Shaders->find(shader->GetName()) != m_Shaders.end(), "Shader already exists!");
		m_Shaders[shader->GetName()] = shader;
	}

	Ref<Shader> ShaderLibrary::Load(const std::string& path)
	{
		auto shader = Shader::Create(path);
		AddShader(shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::Load(const std::string& name, const std::string& path)
	{
		auto shader = Shader::Create(path);
		return shader;
	}

	Ref<Shader> ShaderLibrary::GetShader(const std::string& name)
	{
		ODVM_CORE_ASSERT(m_Shaders.find(name) != m_Shaders.end(), "Shader not found!");
		return m_Shaders.at(name);
	}

}
