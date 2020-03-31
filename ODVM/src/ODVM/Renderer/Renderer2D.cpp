#include "odvmpch.h"
#include "Renderer2D.hpp"

#include "ODVM/Renderer/Buffer.hpp"
#include "ODVM/Renderer/VertexArray.hpp"
#include "ODVM/Renderer/Shader.hpp"

#include "ODVM/Renderer/RenderCommand.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace ODVM
{
	
		struct QuadVertex
	{
		glm::vec3 Position;
		glm::vec4 Color;
		glm::vec2 TexCoord;
		
	};

	struct Renderer2DData
	{
		const uint32_t MaxQuads = 10000;
		const uint32_t MaxVertices = MaxQuads * 4;
		const uint32_t MaxIndices = MaxQuads * 6;

		Ref<VertexArray> QuadVA;
		Ref<VertexBuffer> QuadVB;
		Ref<Shader> TS;
		Ref<Texture2D> WhiteTexture;
		
		uint32_t QuadIndexCount = 0;

		QuadVertex* QuadVertexBufferBase = nullptr;
		QuadVertex* QuadVertexBufferPtr = nullptr;
	};
    


	static Renderer2DData s_Data;

	void Renderer2D::Init()
	{
		ODVM_PROFILE_FUNCTION();


		s_Data.QuadVA = ODVM::VertexArray::Create();

		s_Data.QuadVB = VertexBuffer::Create(s_Data.MaxVertices * sizeof(QuadVertex));

		ODVM::BufferLayout layout = {
			{ODVM::ShaderDataType::Float3, "a_Position"},
			{ODVM::ShaderDataType::Float3, "a_Color"},
			{ODVM::ShaderDataType::Float2, "a_TextureCoords"}
		};

		s_Data.QuadVB->SetLayout(layout);
		s_Data.QuadVA->AddVertexBuffer(s_Data.QuadVB);
		
		s_Data.QuadVertexBufferBase = new QuadVertex[s_Data.MaxVertices];

		uint32_t* quadIndices = new uint32_t[s_Data.MaxIndices];
		
		for(uint32_t i = 0; i < s_Data.MaxIndices; i+=6)
		{
			quadIndices[i+0] = offset + 0;
			quadIndices[i+0] = offset + 1;
			quadIndices[i+0] = offset + 2;

			quadIndices[i+0] = offset + 2;
			quadIndices[i+0] = offset + 3;
			quadIndices[i+0] = offset + 0;
			
			offset += 4;
		}
		
		Ref<IndexBuffer> quadIB = IndexBuffer::Create(quadIndices, s_Data.MaxIndices);
		s_Data.QuadVA->SetIndexBuffer(quadIB);
		delete[] quadIndices;

		s_Data.WhiteTexture = Texture2D::Create(1, 1);
		uint32_t whiteTextureData = 0xffffffff;
		s_Data.WhiteTexture->SetData(&whiteTextureData, sizeof(uint32_t));

		s_Data.TS = Shader::Create("./assets/shaders/Texture.glsl");
		s_Data.TS->Bind();
		s_Data.TS->SetInt("u_Texture", 0);
	}

	void Renderer2D::Shutdown()
	{
		ODVM_PROFILE_FUNCTION();
	}

	bool Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		ODVM_PROFILE_FUNCTION();
		
		s_Data.QuadIndexCount = 0;

		s_Data.TS->Bind();
		s_Data.TS->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());

		s_Data.QuadVertexBufferPtr = s_Data.QuadVertexBufferBase;

		return true;
	}

	void Renderer2D::EndScene()
	{
		ODVM_PROFILE_FUNCTION();
		
		uint32_t dataSize = (uint8_t*)s_Data.QuadVertexBufferPtr - (uint8_t*)s_Data.QuadVertexBufferBase;
		s_Data.QuadVB->SetData(s_Data.QuadVertexBufferBase, dataSize);
		
		Flush();
	}
	
	void Renderer2D::Flush()
	{
		ODVM_PROFILE_FUNCTION();
		
		RenderCommand::DrawIndexed(s_Data.QuadVA, s_Data.QuadIndexCount);
	}

	void Renderer2D::DrawQuad(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color)
	{
		DrawQuad({ pos.x, pos.y, 0.0f }, size, color);
	}

	void Renderer2D::DrawQuad(const glm::vec3& pos, const glm::vec2& size, const glm::vec4& color)
	{
		ODVM_PROFILE_FUNCTION();
		
		s_Data.QuadVertexBufferPtr->Position = pos;
		s_Data.QuadVertexBufferPtr->Color = color;
		s_Data.QuadVertexBufferPtr->TexCoord = { 0.0f, 0.0f };
		s_Data.QuadVertexBufferPtr++;
		
		s_Data.QuadVertexBufferPtr->Position = { pos.x + size.x, pos.y, 0.0f };
		s_Data.QuadVertexBufferPtr->Color = color;
		s_Data.QuadVertexBufferPtr->TexCoord = { 1.0f, 0.0f };
		s_Data.QuadVertexBufferPtr++;
		
		s_Data.QuadVertexBufferPtr->Position = { pos.x + size.x, pos.y + size.y, 0.0f };
		s_Data.QuadVertexBufferPtr->Color = color;
		s_Data.QuadVertexBufferPtr->TexCoord = { 1.0f, 1.0f };
		s_Data.QuadVertexBufferPtr++;
		
		s_Data.QuadVertexBufferPtr->Position = { pos.x, pos.y + size.y, 0.0f };
		s_Data.QuadVertexBufferPtr->Color = color;
		s_Data.QuadVertexBufferPtr->TexCoord = { 0.0f, 1.0f };
		s_Data.QuadVertexBufferPtr++;
		
		s_Data.QuadIndexCount += 6;
/*
		s_Data.TS->Bind();

		s_Data.TS->SetFloat("u_Size", 1.0f);

		s_Data.WhiteTexture->Bind();

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });
		s_Data.TS->SetMat4("u_Transform", transform);

		s_Data.QuadVA->Bind();
		RenderCommand::DrawIndexed(s_Data->QuadVA);*/
	}

	void Renderer2D::DrawQuad(const glm::vec2& pos, const glm::vec2& size, Ref<Texture2D> texture, float repeatNumber, glm::vec4 tintColor)
	{
		DrawQuad({ pos.x, pos.y, 0.0f }, size, texture, repeatNumber, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec3& pos, const glm::vec2& size, Ref<Texture2D> texture, float repeatNumber, glm::vec4 tintColor)
	{
		ODVM_PROFILE_FUNCTION();

		s_Data.TS->Bind();

		texture->Bind();

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });
		s_Data.TS->SetMat4("u_Transform", transform);
	
		s_Data.TS->SetFloat("u_Size", repeatNumber);
		

		s_Data.TS->SetFloat4("u_Color", tintColor);


		s_Data.QuadVA->Bind();
		RenderCommand::DrawIndexed(s_Data.QuadVA);


	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& pos, const glm::vec2& size, float rotation, const glm::vec4& color)
	{
		DrawRotatedQuad({ pos.x, pos.y, 0.0f }, size, rotation, color);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec2& pos, const glm::vec2& size, float rotation, const Ref<Texture2D> texture, float repeatNumber /*= 1.0f*/, glm::vec4 tintColor)
	{
		DrawRotatedQuad({ pos.x, pos.y, 0.0f }, size, rotation, texture, repeatNumber, tintColor);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& pos, const glm::vec2& size, float rotation, const glm::vec4& color)
	{
		ODVM_PROFILE_FUNCTION();

		s_Data.TS->Bind();

		s_Data.TS->SetFloat4("u_Color", color);
		s_Data.TS->SetFloat("u_Size", 1.0f);

		s_Data.WhiteTexture->Bind();

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::rotate(glm::mat4(1.0f), rotation, { 0.0f, 0.0f, 1.0f }) * glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });
		s_Data.TS->SetMat4("u_Transform", transform);

		s_Data.QuadVA->Bind();
		RenderCommand::DrawIndexed(s_Data.QuadVA);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& pos, const glm::vec2& size, float rotation, const Ref<Texture2D> texture, float repeatNumber /*= 1.0f*/, glm::vec4 tintColor)
	{
		ODVM_PROFILE_FUNCTION();

		s_Data.TS->Bind();

		texture->Bind();

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::rotate(glm::mat4(1.0f), rotation, {0.0f, 0.0f, 1.0f}) * glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });
		s_Data.TS->SetMat4("u_Transform", transform);

		s_Data.TS->SetFloat("u_Size", repeatNumber);


		s_Data.TS->SetFloat4("u_Color", tintColor);


		s_Data.QuadVA->Bind();
		RenderCommand::DrawIndexed(s_Data.QuadVA);

	}
}

