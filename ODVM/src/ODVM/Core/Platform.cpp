#include "odvmpch.h"
#include "Platform.hpp"

#include "ODVM/Core/Core.hpp"

#include "Platform/Windows/Windows.hpp"

namespace ODVM
{

	float Platform::GetTime()
	{
		#ifdef ODVM_PLATFORM_WINDOWS
		return s_Instance->GetTimeImpl();
		#else
        ODVM_CORE_ERROR("ODVM Engine does not support this platform");
		#endif

	}

}

