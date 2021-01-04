#pragma once

// setup dll import/export macros
#ifdef PL_PLATFORM_WINDOWS
	#ifdef PL_BUILD_DLL
		#define PULIO_API __declspec(dllexport)
	#else
		#define PULIO_API __declspec(dllimport)
	#endif
#else 
	#error Pulio only supports windows!
#endif

// helper to set xth bit
#define BIT(x) 1 << x

// debug break helper
#ifdef PL_PLATFORM_WINDOWS
#define PL_DEBUG_BREAK DebugBreak()
#else
#error Pulio only supports windows!
#endif

// assertion helper
// TODO: add a macro to print 'assertion failed' log
#if PL_DEBUG
#define PL_ASSERT(condition, ...) { if(!(condition)) { PULIO_LOG_ERROR(__VA_ARGS__); PL_DEBUG_BREAK; } }
#else
#define PL_ASSERT(...)
#endif

// helper to bind functions
#define FN_BIND_1_ARG(cls, fn)  std::bind(&cls::fn, this, std::placeholders::_1)
#define FN_BIND_2_ARG(cls, fn)  std::bind(&cls::fn, this, std::placeholders::_2)
#define FN_BIND_3_ARG(cls, fn)  std::bind(&cls::fn, this, std::placeholders::_3)
#define FN_BIND_4_ARG(cls, fn)  std::bind(&cls::fn, this, std::placeholders::_4)