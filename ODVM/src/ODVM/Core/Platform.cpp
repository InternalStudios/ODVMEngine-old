#include "odvmpch.h"
#include "Platform.h"

#include "ODVM/Core/Core.h"

#include "Platform/Windows/Windows.h"

namespace ODVM
{

	float Platform::GetTime()
	{
		#ifdef ODVM_PLATFORM_WINDOWS
		return s_Instance->GetTimeImpl();
		#else
		ODVM_CORE_ERROR("ODVM Engine does not support this platform")
		#endif

	}

}

