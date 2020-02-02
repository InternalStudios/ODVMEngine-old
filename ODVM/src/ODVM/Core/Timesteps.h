#pragma once

#include "ODVM/Core/Platform.h"

namespace ODVM
{
	class Timestep
	{
	public:
		Timestep()
			: m_Time(0.0f)
		{
			deltatime();
		}

		void deltatime()
		{
			m_Time = 0.0f;
			float time = Platform::GetTime();
			m_Time = (time - m_LastFrameTime);
			m_LastFrameTime = time;
		}

		operator float() const { return m_Time; }

		float getSeconds() { return m_Time; }
		float getMilliseconds() { return m_Time * 1000; }
	private:
		float m_Time = 0.0f;
		float m_LastFrameTime;
	};
}