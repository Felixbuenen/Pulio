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

// helper to bind functions
#define FN_BIND_1_ARG(cls, fn)  std::bind(&cls::fn, this, std::placeholders::_1)
#define FN_BIND_2_ARG(cls, fn)  std::bind(&cls::fn, this, std::placeholders::_2)
#define FN_BIND_3_ARG(cls, fn)  std::bind(&cls::fn, this, std::placeholders::_3)
#define FN_BIND_4_ARG(cls, fn)  std::bind(&cls::fn, this, std::placeholders::_4)