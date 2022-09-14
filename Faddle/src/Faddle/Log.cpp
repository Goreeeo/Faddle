#include "fmpch.h"

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Faddle {
	std::shared_ptr<spdlog::logger> Log::s_Logger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %v%$");
		s_Logger = spdlog::stdout_color_mt("CORE");
		s_Logger->set_level(spdlog::level::trace);
	}
}