#include "odvmpch.h"
#include "OpenGLShader.h"

#include <fstream>

#include <glm/gtc/type_ptr.hpp>

namespace ODVM
{

	static GLenum ShaderTypeFromString(const std::string& type)
	{
		if (type == "vertex") { return GL_VERTEX_SHADER; }
		if (type == "fragment" || type == "pixel") { return GL_FRAGMENT_SHADER; }

		ODVM_CORE_ASSERT(false, "Unknown Shader Type!");
		return 0;
	}

	OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
		: m_Name(name)
	{
		ODVM_PROFILE_FUNCTION();

		std::unordered_map<GLenum, std::string> map;
		map[GL_VERTEX_SHADER] = vertexSrc;
		map[GL_FRAGMENT_SHADER] = fragmentSrc;
		Compile(map);

	}

	OpenGLShader::OpenGLShader(const std::string& path)
	{
		ODVM_PROFILE_FUNCTION();

		std::string shaderSrc = ReadFile(path);

		Compile(PreProcess(shaderSrc));

		auto lastSlash = path.find_last_of("/\\");
		lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;
		auto lastDot = path.rfind(".");
		auto count = lastDot == std::string::npos ? path.size() - lastSlash : lastDot - lastSlash;
		m_Name = path.substr(lastSlash, count);
	}

	std::string OpenGLShader::ReadFile(const std::string& path)
	{
		ODVM_PROFILE_FUNCTION();

		std::string result;
		std::ifstream in(path, std::ios::in | std::ios::binary);
		if (in)
		{
			in.seekg(0, std::ios::end);
			result.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&result[0], result.size());
			in.close();
		}
		else
		{
			ODVM_CORE_ERROR("Could not open file '{0}'", path);
		}

		return result;

	}

	std::unordered_map<GLenum, std::string> OpenGLShader::PreProcess(const std::string& src)
	{
		ODVM_PROFILE_FUNCTION();
		std::unordered_map<GLenum, std::string> shaderSrcs;

		const char* typeToken = "#type";
		size_t typeTokenLength = strlen(typeToken);
		size_t pos = src.find(typeToken, 0);
		while (pos != std::string::npos)
		{
			size_t eol = src.find_first_of("\r\n", pos);
			ODVM_CORE_ASSERT(eol != std::string::npos, "Syntax Error");
			size_t begin = pos + typeTokenLength + 1;
			std::string type = src.substr(begin, eol - begin);
			ODVM_CORE_ASSERT(ShaderTypeFromString(type), "Invalid shader type!");

			size_t nextLinePos = src.find_first_not_of("\r\n", eol);
			ODVM_CORE_ASSERT(nextLinePos != std::string::npos, "Syntax error");
			pos = src.find(typeToken, nextLinePos);
			shaderSrcs[ShaderTypeFromString(type)] = (pos == std::string::npos) ? src.substr(nextLinePos) : src.substr(nextLinePos, pos - nextLinePos);
		}
		return shaderSrcs;
	}

	void OpenGLShader::Compile(const std::unordered_map<GLenum, std::string>& shaderSrc)
	{
		ODVM_PROFILE_FUNCTION();

		GLuint program = glCreateProgram();
		ODVM_CORE_ASSERT(shaderSrc.size() <= 2, "Too many shaders");
		std::array<GLenum, 2> glShaderIDs;
		int shaderSize = 0;
		for (auto& kv : shaderSrc)
		{
			GLenum type = kv.first;
			const std::string& source = kv.second;

			GLuint shader = glCreateShader(type);
			const GLchar* sourceCStr = source.c_str();
			glShaderSource(shader, 1, &sourceCStr, 0);

			glCompileShader(shader);

			GLint isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				// The maxLength includes the NULL character
				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

				// We don't need the shader anymore.
				glDeleteShader(shader);

				ODVM_CORE_ERROR("{0}", infoLog.data());
				ODVM_CORE_ASSERT(false, "Shader compilation failed!");

				break;
			}
			glAttachShader(program, shader);

			glShaderIDs[shaderSize++] = shader;
		}


		m_RendererID = program;

		// Link our program
		glLinkProgram(program);

		// Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

			// We don't need the program anymore.
			glDeleteProgram(program);
			// Don't leak shaders either.
			for (auto shader : glShaderIDs)
			{
				glDeleteShader(shader);
			}

			ODVM_CORE_ERROR("{0}", infoLog.data());
			ODVM_CORE_ASSERT(false, "Shader linking failed!");
			return;
		}

		// Always detach shaders after a successful link.

		for (auto shader : glShaderIDs)
		{
			glDetachShader(m_RendererID, shader);
			glDeleteShader(shader);
		}

	}

	OpenGLShader::~OpenGLShader()
	{
		ODVM_PROFILE_FUNCTION();

		glDeleteProgram(m_RendererID);
	}

	void OpenGLShader::Bind() const
	{
		ODVM_PROFILE_FUNCTION();

		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Unbind() const
	{
		ODVM_PROFILE_FUNCTION();

		glUseProgram(0);
	}

	void OpenGLShader::UploadUniformMat4(const std::string& name, const glm::mat4& mat4)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat4));
	}


	void OpenGLShader::SetInt(const std::string& name, int value)
	{
		UploadUniformInt(name, value);
	}

	void OpenGLShader::SetFloat(const std::string& name, float value)
	{
		UploadUniformFloat(name, value);
	}

	void OpenGLShader::SetFloat2(const std::string& name, const glm::vec2& vec2)
	{
		UploadUniformFloat2(name, vec2);
	}

	void OpenGLShader::SetFloat3(const std::string& name, const glm::vec3& vec3)
	{
		UploadUniformFloat3(name, vec3);
	}

	void OpenGLShader::SetFloat4(const std::string& name, const glm::vec4& vec4)
	{
		UploadUniformFloat4(name, vec4);
	}

	void OpenGLShader::SetMat3(const std::string& name, const glm::mat3& mat3)
	{
		UploadUniformMat3(name, mat3);
	}

	void OpenGLShader::SetMat4(const std::string& name, const glm::mat4& mat4)
	{
		UploadUniformMat4(name, mat4);
	}

	void OpenGLShader::UploadUniformFloat4(const std::string& name, const glm::vec4& vec4)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform4fv(location, 1, glm::value_ptr(vec4));
	}

	void OpenGLShader::UploadUniformInt(const std::string& name, int value)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform1i(location, value);
	}

	void OpenGLShader::UploadUniformFloat(const std::string& name, float value)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform1fv(location, 1, &value);
	}

	void OpenGLShader::UploadUniformFloat2(const std::string& name, const glm::vec2& vec2)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform2fv(location, 1, glm::value_ptr(vec2));
	}

	void OpenGLShader::UploadUniformFloat3(const std::string& name, const glm::vec3& vec3)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform3fv(location, 1, glm::value_ptr(vec3));
	}

	void OpenGLShader::UploadUniformMat3(const std::string& name, const glm::mat3& mat3)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(mat3));
	}

}