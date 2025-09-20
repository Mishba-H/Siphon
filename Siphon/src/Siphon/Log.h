#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Siphon {
	class SIPHON_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define SPN_CORE_TRACE(...) ::Siphon::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SPN_CORE_INFO(...)  ::Siphon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SPN_CORE_WARN(...)  ::Siphon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SPN_CORE_ERROR(...) ::Siphon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SPN_CORE_FATAL(...) ::Siphon::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client log macros
#define SPN_TRACE(...) ::Siphon::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SPN_INFO(...)  ::Siphon::Log::GetClientLogger()->info(__VA_ARGS__)
#define SPN_WARN(...)  ::Siphon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SPN_ERROR(...) ::Siphon::Log::GetClientLogger()->error(__VA_ARGS__)
#define SPN_FATAL(...) ::Siphon::Log::GetClientLogger()->fatal(__VA_ARGS__)