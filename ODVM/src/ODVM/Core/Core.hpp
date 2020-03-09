#pragma once

#include <memory>

#ifdef _WIN32
	#ifdef _WIN64
		#define ODVM_PLATFORM_WINDOWS
#else
		#error "Windows X86 is not supported"
	#endif
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator not supported"
	#elif TARGET_OS_IPHONE == 1
		#define ODVM_PLATFORM_IOS
		#error "IOS is not supported"
	#elif TARGET_OS_MAC == 1
		#define ODVM_PLATFORM_MACOS
#else
		#error "Unknown Apple platform"
	#endif
#elif defined(__ANDROID__)
	#define ODVM_PLATFORM_ANDROID
	#error "Android is not supported"
#elif defined(__linux__)
	#define ODVM_PLATFORM_LINUX
	#error "Linux is not supported"
#else
	#error "Unknown platform"
#endif


// DLL support
#ifdef ODVM_PLATFORM_WINDOWS
	#if ODVM_DYNAMIC_LINK
		#ifdef ODVM_BUILD_DLL
			#define ODVM_API __declspec(dllexport)
		#else
			#define ODVM_API __declspec(dllimport)
		#endif
	#else
		#define ODVM_API
	#endif
#endif // End of DLL support

#ifdef ODVM_DEBUG
	#define ODVM_ENABLE_ASSERTS
#endif

#ifdef ODVM_ENABLE_ASSERTS
#ifdef ODVM_PLATFORM_WINDOWS
	#define ODVM_ASSERT(x, ...) {if(!(x)) { ODVM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define ODVM_CORE_ASSERT(x, ...) {if(!(x)) { ODVM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
#define ODVM_ASSERT(x, ...) {if(!(x)) { ODVM_ERROR("Assertion Failed: {0}", __VA_ARGS__);}}
#define ODVM_CORE_ASSERT(x, ...) {if(!(x)) { ODVM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);}}
#endif
#else
	#define ODVM_ASSERT(x, ...)
	#define ODVM_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
namespace ODVM
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}
