#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#include "Core.h"

namespace Pulio {
	
	class PULIO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> m_coreLogger;
		static std::shared_ptr<spdlog::logger> m_clientLogger;
	};
}

// set logging macros to be used by engine and client
#ifdef PL_BUILD_DLL
	#define PULIO_LOG_INFO(...)     ::Pulio::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define PULIO_LOG_DEBUG(...)    ::Pulio::Log::GetCoreLogger()->debug(__VA_ARGS__)
	#define PULIO_LOG_WARNING(...)  ::Pulio::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define PULIO_LOG_ERROR(...)    ::Pulio::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define PULIO_LOG_CRITICAL(...) ::Pulio::Log::GetCoreLogger()->critical(__VA_ARGS__)
#else
	#define PULIO_LOG_INFO(...)     ::Pulio::Log::GetClientLogger()->info(__VA_ARGS__)
	#define PULIO_LOG_DEBUG(...)    ::Pulio::Log::GetClientLogger()->debug(__VA_ARGS__)
	#define PULIO_LOG_WARNING(...)  ::Pulio::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define PULIO_LOG_ERROR(...)    ::Pulio::Log::GetClientLogger()->error(__VA_ARGS__)
	#define PULIO_LOG_CRITICAL(...) ::Pulio::Log::GetClientLogger()->critical(__VA_ARGS__)
#endif