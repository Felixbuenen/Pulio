#include "plpch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Pulio {

	std::shared_ptr<spdlog::logger> Log::m_coreLogger;
	std::shared_ptr<spdlog::logger> Log::m_clientLogger;

	void Log::Init()
	{
		// init loggers
		m_coreLogger = spdlog::stdout_color_mt("PULIO");
		m_clientLogger = spdlog::stdout_color_mt("GAME");

		// set format and level
		m_coreLogger->set_level(spdlog::level::trace);
		m_clientLogger->set_level(spdlog::level::trace);
		spdlog::set_pattern("%^[%T] (%l) %n: %v%$");
	}

}