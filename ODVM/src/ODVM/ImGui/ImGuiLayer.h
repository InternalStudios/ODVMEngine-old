#pragma once

#include "ODVM/Layer.h"
#include "ODVM/Events/MouseEvent.h"
#include "ODVM/Events/ApplicationEvent.h"
#include "ODVM/Events/KeyEvent.h"

namespace ODVM
{
	class ODVM_API ImGuiLayer : public Layer
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