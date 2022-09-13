#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Faddle {
	class FADDLE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }

	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};
}

#define FM_ERROR(...) ::Faddle::Log::GetLogger()->error(__VA_ARGS__)
#define FM_INFO(...) ::Faddle::Log::GetLogger()->info(__VA_ARGS__)
#define FM_WARN(...) ::Faddle::Log::GetLogger()->warn(__VA_ARGS__)
#define FM_TRACE(...) ::Faddle::Log::GetLogger()->trace(__VA_ARGS__)
#define FM_FATAL(...) ::Faddle::Log::GetLogger()->fatal(__VA_ARGS__)