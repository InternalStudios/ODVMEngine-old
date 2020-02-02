#pragma once

namespace ODVM
{
	class Platform
	{
	public:
		static float GetTime();
	private:
		virtual float GetTimeImpl() = 0;

		static Platform* s_Instance;
	};
}