#include "odvmpch.h"
#include "CameraControllers.hpp"

#include "ODVM/Core/Input.hpp"
#include "ODVM/Core/KeyCodes.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ODVM/Core/Application.hpp"

namespace ODVM
{

	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation, float cameraMoveSpeed, float cameraRotationSpeed)
		: m_Rotation(rotation), m_AspectRatio(aspectRatio), m_CameraSpeed(cameraMoveSpeed), m_CameraRotationSpeed(cameraRotationSpeed), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel)
	{
	
	}

	void OrthographicCameraController::OnUpdate(Timestep ts)
	{
		ODVM_PROFILE_FUNCTION();

		if (ODVM::Input::IsKeyPressed(ODVM_KEY_W)) {

			m_CameraPosition.x += -sin(glm::radians(m_CameraRotation.z)) * m_CameraSpeed * ts * (m_ZoomLevel * 0.5f);
			m_CameraPosition.y += cos(glm::radians(m_CameraRotation.z)) * m_CameraSpeed * ts * (m_ZoomLevel * 0.5f);

		}
		if (ODVM::Input::IsKeyPressed(ODVM_KEY_S))
		{
			m_CameraPosition.x -= -sin(glm::radians(m_CameraRotation.z)) * m_CameraSpeed * ts * (m_ZoomLevel * 0.5f);
			m_CameraPosition.y -= cos(glm::radians(m_CameraRotation.z)) * m_CameraSpeed * ts * (m_ZoomLevel * 0.5f);
		}
		
		if (ODVM::Input::IsKeyPressed(ODVM_KEY_A))
		{
			m_CameraPosition.x -= cos(glm::radians(m_CameraRotation.z)) * m_CameraSpeed * ts * (m_ZoomLevel * 0.5f);	
			m_CameraPosition.y -= sin(glm::radians(m_CameraRotation.z)) * m_CameraSpeed * ts * (m_ZoomLevel * 0.5f);
		}

		if (ODVM::Input::IsKeyPressed(ODVM_KEY_D))
		{
			m_CameraPosition.x += cos(glm::radians(m_CameraRotation.z)) * m_CameraSpeed * ts * (m_ZoomLevel * 0.5f);
			m_CameraPosition.y += sin(glm::radians(m_CameraRotation.z)) * m_CameraSpeed * ts * (m_ZoomLevel * 0.5f);
		}

		if (m_Rotation) {
			if (ODVM::Input::IsKeyPressed(ODVM_KEY_Q))
				m_CameraRotation.z += m_CameraRotationSpeed * ts;

			if (ODVM::Input::IsKeyPressed(ODVM_KEY_E))
				m_CameraRotation.z -= m_CameraRotationSpeed * ts;

			if (m_CameraRotation.z > 180.0f)
				m_CameraRotation.z -= 360.0f;
			else if (m_CameraRotation.z < -180.0f)
				m_CameraRotation.z += 360.0f;


			m_Camera.SetRotation(m_CameraRotation);
		}

		m_Camera.SetPosition(m_CameraPosition);

		m_Camera.OnUpdate();
	}

	void OrthographicCameraController::OnEvent(Event& e)
	{
		ODVM_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OrthographicCameraController::OnWindowResize));
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		ODVM_PROFILE_FUNCTION();

		m_ZoomLevel -= e.GetYOffset() * 0.1f;
		//m_ZoomLevel = std::max(m_ZoomLevel, 0.01f);
		//m_ZoomLevel = std::min(m_ZoomLevel, 20.0f);

		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}

	bool OrthographicCameraController::OnWindowResize(WindowResizeEvent& e)
	{
		ODVM_PROFILE_FUNCTION();

		m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}

	PerspectiveCameraController::PerspectiveCameraController(float aspectRatio, bool rotation, float cameraMoveSpeed, float cameraRotationSpeed)
		: m_Rotation(rotation), m_AspectRatio(aspectRatio), m_CameraSpeed(cameraMoveSpeed), m_CameraRotationSpeed(cameraRotationSpeed), m_Camera(m_AspectRatio), m_CameraFront(0.0f, 0.0f, -1.0f), m_CameraUp(0.0f, 1.0f, 0.0f), m_Up(0.0f, 1.0f, 0.0f), m_CameraRight(glm::normalize(glm::cross(m_Up, m_CameraDirection))), view(glm::lookAt(m_CameraPosition, m_CameraPosition + m_CameraFront, m_CameraUp))
	{
	
	}

	void PerspectiveCameraController::OnUpdate(Timestep ts)
	{
		ODVM_PROFILE_FUNCTION();

		m_CameraUp = glm::normalize(glm::cross(m_CameraRight, m_CameraFront));
		m_CameraRight = glm::normalize(glm::cross(m_CameraFront, m_Up));

		m_CameraCurrentSpeed = m_CameraSpeed * ts;

		if (ODVM::Input::IsKeyPressed(ODVM_KEY_W)) {

			m_CameraPosition += m_CameraCurrentSpeed * m_CameraFront;

		}
		if (ODVM::Input::IsKeyPressed(ODVM_KEY_S))
		{
			m_CameraPosition -= m_CameraCurrentSpeed * m_CameraFront;
		}
		
		if (ODVM::Input::IsKeyPressed(ODVM_KEY_A))
		{
			m_CameraPosition -= m_CameraRight * m_CameraCurrentSpeed;
		}

		if (ODVM::Input::IsKeyPressed(ODVM_KEY_D))
		{
			m_CameraPosition += m_CameraRight * m_CameraCurrentSpeed;
		}

		/*if (m_Rotation) {
			if (ODVM::Input::IsKeyPressed(ODVM_KEY_Q))
				m_CameraRotation.z += m_CameraRotationSpeed * ts;

			if (ODVM::Input::IsKeyPressed(ODVM_KEY_E))
				m_CameraRotation.z -= m_CameraRotationSpeed * ts;

			if (m_CameraRotation.z > 180.0f)
				m_CameraRotation.z -= 360.0f;
			else if (m_CameraRotation.z < -180.0f)
				m_CameraRotation.z += 360.0f;


			//m_Camera.SetRotation(m_CameraRotation);
		}*/



		//m_Camera.SetPosition(m_CameraPosition);



		glm::mat4 view;
		view = glm::lookAt(m_CameraPosition, m_CameraPosition + m_CameraFront, m_Up);
		m_Camera.SetView(view);

		m_Camera.OnUpdate();
	}

	void PerspectiveCameraController::OnEvent(Event& e)
	{
		ODVM_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(PerspectiveCameraController::OnWindowResize));
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(PerspectiveCameraController::OnMouseMoved));
	}

	bool PerspectiveCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		ODVM_PROFILE_FUNCTION();

		m_ZoomLevel -= e.GetYOffset() * 0.1f;
		//m_ZoomLevel = std::max(m_ZoomLevel, 0.01f);
		//m_ZoomLevel = std::min(m_ZoomLevel, 20.0f);

		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}

	bool PerspectiveCameraController::OnWindowResize(WindowResizeEvent& e)
	{
		ODVM_PROFILE_FUNCTION();

		m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
	bool PerspectiveCameraController::OnMouseMoved(MouseMovedEvent& e)
	{
		ODVM_PROFILE_FUNCTION();

		if(m_FirstMouse)
		{
			m_LastMouseX = e.GetX();
			m_LastMouseY = e.GetY();
			m_FirstMouse = false;
		}

		float xOffset = e.GetX() - m_LastMouseX;
		float yOffset = m_LastMouseY - e.GetY();

		m_LastMouseX = e.GetX();
		m_LastMouseY = e.GetY();

		float sensitivity = 0.05f;
		xOffset *= sensitivity;
		yOffset *= sensitivity;

		m_Yaw += xOffset;
		m_Pitch += yOffset;

		if(m_Pitch > 89.0f)
			m_Pitch = 89.0f;
		if(m_Pitch < -89.0f)
			m_Pitch = -89.0f;
		
		glm::vec3 direction;
		direction.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		direction.y = sin(glm::radians(m_Pitch));
		direction.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		m_CameraFront = glm::normalize(direction);
		return false;
	}

}

