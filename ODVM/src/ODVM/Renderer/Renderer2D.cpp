#include "odvmpch.h"
#include "Renderer2D.h"

#include "ODVM/Renderer/Buffer.h"
#include "ODVM/Renderer/VertexArray.h"
#include "ODVM/Renderer/Shader.h"

#include "ODVM/Renderer/RenderCommand.h"

#include <glm/gtc/matrix_transform.hpp>

namespace ODVM
{

	struct Renderer2DData
	{
		Ref<VertexArray> QuadVA;
		Ref<Shader> TS;
		Ref<Texture2D> WhiteTexture;

	};

	static Renderer2DData* s_Data;

	void Renderer2D::Init()
	{
		ODVM_PROFILE_FUNCTION();

		s_Data = new Renderer2DData();


		s_Data->QuadVA = ODVM::VertexArray::Create();


		float vertices[4 * 5] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.0f, 0.0f, 1.0f
		};

		Ref<VertexBuffer> vertexBuffer;
		vertexBuffer = VertexBuffer::Create(vertices, sizeof(vertices));

		ODVM::BufferLayout layout = {
			{ODVM::ShaderDataType::Float3, "a_Position"},
			{ODVM::ShaderDataType::Float2, "a_TextureCoords"}
		};

		vertexBuffer->SetLayout(layout);
		s_Data->QuadVA->AddVertexBuffer(vertexBuffer);

		uint32_t indices[4] = { 0, 1, 2, 3 };
		Ref<IndexBuffer> indexBuffer;
		indexBuffer = IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
		s_Data->QuadVA->SetIndexBuffer(indexBuffer);

		s_Data->WhiteTexture = Texture2D::Create(1, 1);
		uint32_t whiteTextureData = 0xffffffff;
		s_Data->WhiteTexture->SetData(&whiteTextureData, sizeof(uint32_t));

		s_Data->TS = Shader::Create("assets/shaders/Texture.glsl");
		s_Data->TS->Bind();
		s_Data->TS->SetInt("u_Texture", 0);
	}

	void Renderer2D::Shutdown()
	{
		ODVM_PROFILE_FUNCTION();

		delete s_Data;
	}

	bool Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		ODVM_PROFILE_FUNCTION();

		s_Data->TS->Bind();
		s_Data->TS->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());

		

		return true;
	}

	void Renderer2D::EndScene()
	{
		ODVM_PROFILE_FUNCTION();
	}

	void Renderer2D::DrawQuad(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color)
	{
		DrawQuad({ pos.x, pos.y, 0.0f }, size, color);
	}

	void Renderer2D::DrawQuad(const glm::vec3& pos, const glm::vec2& size, const glm::vec4& color)
	{
		ODVM_PROFILE_FUNCTION();

		s_Data->TS->Bind();
		
		s_Data->TS->SetFloat4("u_Color", color);
		s_Data->TS->SetFloat("u_Size", 1.0f);

		s_Data->WhiteTexture->Bind();

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });
		s_Data->TS->SetMat4("u_Transform", transform);

		s_Data->QuadVA->Bind();
		RenderCommand::DrawIndexed(s_Data->QuadVA);
	}

	void Renderer2D::DrawQuad(const glm::vec2& pos, const glm::vec2& size, Ref<Texture2D> texture, float repeatNumber, glm::vec4 tintColor)
	{
		DrawQuad({ pos.x, pos.y, 0.0f }, size, texture, repeatNumber, tintColor);
	}

	void Renderer2D::DrawQuad(const glm::vec3& pos, const glm::vec2& size, Ref<Texture2D> texture, float repeatNumber, glm::vec4 tintColor)
	{
		ODVM_PROFILE_FUNCTION();

		s_Data->TS->Bind();

		texture->Bind();

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });
		s_Data->TS->SetMat4("u_Transform", transform);
	
		s_Data->TS->SetFloat("u_Size", repeatNumber);
		

		s_Data->TS->SetFloat4("u_Color", tintColor);


		s_Data->QuadVA->Bind();
		RenderCommand::DrawIndexed(s_Data->QuadVA);


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

		s_Data->TS->Bind();

		s_Data->TS->SetFloat4("u_Color", color);
		s_Data->TS->SetFloat("u_Size", 1.0f);

		s_Data->WhiteTexture->Bind();

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::rotate(glm::mat4(1.0f), rotation, { 0.0f, 0.0f, 1.0f }) * glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });
		s_Data->TS->SetMat4("u_Transform", transform);

		s_Data->QuadVA->Bind();
		RenderCommand::DrawIndexed(s_Data->QuadVA);
	}

	void Renderer2D::DrawRotatedQuad(const glm::vec3& pos, const glm::vec2& size, float rotation, const Ref<Texture2D> texture, float repeatNumber /*= 1.0f*/, glm::vec4 tintColor)
	{
		ODVM_PROFILE_FUNCTION();

		s_Data->TS->Bind();

		texture->Bind();

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::rotate(glm::mat4(1.0f), rotation, {0.0f, 0.0f, 1.0f}) * glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });
		s_Data->TS->SetMat4("u_Transform", transform);

		s_Data->TS->SetFloat("u_Size", repeatNumber);


		s_Data->TS->SetFloat4("u_Color", tintColor);


		s_Data->QuadVA->Bind();
		RenderCommand::DrawIndexed(s_Data->QuadVA);

	}

}

