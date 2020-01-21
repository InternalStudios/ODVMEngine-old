#pragma once

#include "ODVM/Input.h"

namespace ODVM
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		bool IsMouseButtonPressedImpl(int button) override;


		float GetMouseXImpl() override;


		float GetMouseYImpl() override;


		std::pair<float, float> GetMousePosImpl() override;

	};
}