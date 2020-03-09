#pragma once

#include "ODVM/Core/Layer.hpp"
#include "ODVM/Events/MouseEvent.hpp"
#include "ODVM/Events/ApplicationEvent.hpp"
#include "ODVM/Events/KeyEvent.hpp"

namespace ODVM
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}
