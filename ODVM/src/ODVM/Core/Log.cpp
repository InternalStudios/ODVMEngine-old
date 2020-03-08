#include <odvmpch.h>
#include "Log.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace ODVM
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init(const std::string& client_name)
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("ODVM");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt(client_name);
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}
