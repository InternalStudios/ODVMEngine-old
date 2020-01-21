#pragma once

#ifdef ODVM_PLATFORM_WINDOWS
	#ifdef ODVM_BUILD_DLL
		#define ODVM_API __declspec(dllexport)
	#else
		#define ODVM_API __declspec(dllimport)
	#endif 
#else
	#error Hazel Only Supports Windows!
#endif

#ifdef ODVM_DEBUG
	#define ODVM_ENABLE_ASSERTS
#endif

#ifdef ODVM_ENABLE_ASSERTS
	#define ODVM_ASSERT(x, ...) {if(!(x)) { ODVM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define ODVM_CORE_ASSERT(x, ...) {if(!(x)) { ODVM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define ODVM_ASSERT(x, ...)
	#define ODVM_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)