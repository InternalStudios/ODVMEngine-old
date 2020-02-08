#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace ODVM
{
	class ODVM_API Log
	{
	public:
		static void Init(const std::string& client_name);

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define ODVM_CORE_INFO(...) ::ODVM::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ODVM_CORE_TRACE(...) ::ODVM::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ODVM_CORE_WARN(...) ::ODVM::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ODVM_CORE_ERROR(...) ::ODVM::Log::GetCoreLogger()->error(__VA_ARGS__)

//Client log macros
#define ODVM_INFO(...) ::ODVM::Log::GetClientLogger()->info(__VA_ARGS__)
#define ODVM_TRACE(...) ::ODVM::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ODVM_WARN(...) ::ODVM::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ODVM_ERROR(...) ::ODVM::Log::GetClientLogger()->error(__VA_ARGS__)
