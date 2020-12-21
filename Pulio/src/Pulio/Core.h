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