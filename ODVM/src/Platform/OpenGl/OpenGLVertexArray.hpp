#pragma once

#include "ODVM/Renderer/VertexArray.hpp"

namespace ODVM
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();

		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& buffer) override;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& buffer) override;


		virtual const std::vector<Ref<VertexBuffer>>& OpenGLVertexArray::GetVertexBuffers() const override { return m_VertexBuffers; }
		virtual const Ref<IndexBuffer>& OpenGLVertexArray::GetIndexBuffer() const override { return m_IndexBuffer; }

	private:
		uint32_t m_RendererID;
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IndexBuffer;
	};
}
