#pragma once

#include <glm/glm.hpp>

namespace ODVM
{

	class Camera
	{
	public:
		virtual ~Camera() {}

		virtual const glm::vec3& GetPosition() const = 0;
		virtual void SetPosition(const glm::vec3& position) = 0;
		virtual const glm::vec2& GetRotation() const = 0;
		virtual void SetRotation(const glm::vec2& rotation) = 0;

		virtual void SetProjection(float left, float right, float bottom, float top) = 0;

		virtual const glm::mat4& GetProjectionMatrix() const = 0;
		virtual const glm::mat4& GetViewMatrix() const = 0;
		virtual const glm::mat4& GetViewProjectionMatrix() const = 0;

		virtual void OnUpdate() = 0;
	};

	class OrthographicCamera : public Camera
	{
	public:
		OrthographicCamera(float left, float right, float bottom, float top);

		virtual const glm::vec3& GetPosition() const override { return m_Position; }
		virtual void SetPosition(const glm::vec3& position) override { m_Position = position; }

		virtual const glm::vec2& GetRotation() const override { return m_Rotation; }
		virtual void SetRotation(const glm::vec2& rotation) override { m_Rotation.y = rotation.y; }

		virtual void SetProjection(float left, float right, float bottom, float top) override;

		virtual const glm::mat4& GetProjectionMatrix() const override { return m_ProjectionMatrix; }
		virtual const glm::mat4& GetViewMatrix() const override { return m_ViewMatrix; }
		virtual const glm::mat4& GetViewProjectionMatrix() const override { return m_ViewProjectionMatrix; }


		virtual void OnUpdate() override;

	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
		glm::vec2 m_Rotation = { 0.0f, 0.0f };


	};

	class PerspectiveCamera : public Camera
	{
	public:
		PerspectiveCamera(float aspectRatio);

		virtual const glm::vec3& GetPosition() const override { return m_Position; }
		virtual void SetPosition(const glm::vec3& position) override { m_Position = position; }

		virtual const glm::vec2& GetRotation() const override { return blank; }
		virtual void SetRotation(const glm::vec2& rotation) override { }

		virtual void SetProjection(float aspectRatio);
		virtual void SetProjection(float left, float right, float bottom, float top) override {}
		void SetView(const glm::mat4& view) {m_ViewMatrix = view; m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;}


		virtual const glm::mat4& GetProjectionMatrix() const override { return m_ProjectionMatrix; }
		virtual const glm::mat4& GetViewMatrix() const override { return m_ViewMatrix; }
		virtual const glm::mat4& GetViewProjectionMatrix() const override { return m_ViewProjectionMatrix; }


		virtual void OnUpdate() override;

	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Position = {0.0f, 0.0f, 0.0f};

		glm::vec2 blank = {0.0f, 0.0f};

	};
}
