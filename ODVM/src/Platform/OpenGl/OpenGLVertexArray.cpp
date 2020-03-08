#include "odvmpch.h"
#include "OpenGLVertexArray.h"

#include<glad/glad.h>

namespace ODVM
{

	static GLenum ShaderDataTypeToOpenGL(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::None:
			return NULL;
		case ShaderDataType::Float:
			return GL_FLOAT;
		case ShaderDataType::Float2:
			return GL_FLOAT;
		case ShaderDataType::Float3:
			return GL_FLOAT;
		case ShaderDataType::Float4:
			return GL_FLOAT;
		case ShaderDataType::Mat3:
			return GL_FLOAT;
		case ShaderDataType::Mat4:
			return GL_FLOAT;
		case ShaderDataType::Int:
			return GL_INT;
		case ShaderDataType::Int2:
			return GL_INT;
		case ShaderDataType::Int3:
			return GL_INT;
		case ShaderDataType::Int4:
			return GL_INT;
		case ShaderDataType::Bool:
			return GL_BOOL;
		}

		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		ODVM_PROFILE_FUNCTION();
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		ODVM_PROFILE_FUNCTION();

		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		ODVM_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		ODVM_PROFILE_FUNCTION();

		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& buffer)
	{
		ODVM_PROFILE_FUNCTION();

		ODVM_CORE_ASSERT(buffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");
		
		glBindVertexArray(m_RendererID);
		buffer->Bind();

		uint32_t index = 0;
		const auto& layout = buffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, 
				element.GetComponentCount(), 
				ShaderDataTypeToOpenGL(element.Type), 
				element.Normalized ? GL_TRUE : GL_FALSE, 
				layout.GetStride(), 
				(const void*)element.Offset);
			index++;
		}

		m_VertexBuffers.push_back(buffer);

	}

	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& buffer)
	{
		ODVM_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
		buffer->Bind();

		m_IndexBuffer = buffer; 
	}



}

