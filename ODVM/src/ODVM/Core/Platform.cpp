#include "odvmpch.h"
#include "Platform.hpp"

#include "ODVM/Core/Core.hpp"

#include "Platform/Windows/Windows.hpp"

namespace ODVM
{

	float Platform::GetTime()
	{
        #ifdef ODVM_UNSUPPORTED_PLATFORM
        ODVM_CORE_ERROR("ODVM Engine does not support this platform");
        return 0.0f;
        #endif
		return s_Instance->GetTimeImpl();
	}

}

