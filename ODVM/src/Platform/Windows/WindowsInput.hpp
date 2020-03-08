#pragma once

#include "ODVM/Core/Core.hpp"
#include "ODVM/Core/Input.hpp"

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
