#pragma once

#ifdef FM_PLATFORM_WINDOWS
	#ifdef FM_BUILD_DLL
		#define FADDLE_API __declspec(dllexport)
	#else
		#define FADDLE_API __declspec(dllimport)
	#endif
#else
	#error Get some Windows running.
#endif

#define BIT(x) (1 << x)

#define SUPPRESS_ALL_WARNING _Pragma("GCC diagnostic push") __pragma(warning( push ))
#define STOP_SUPPRESS_ALL_WARNING _Pragma("GCC diagnostic pop") __pragma(warning( pop ))
#define SUPPRESS_WARNING(code, gccname) DO_PRAGMA(GCC diagnostic ignored #gccname) __pragma(warning( disable : code ))
#define SUPPRESS_WARNING_VS(code) __pragma(warning( disable : code ))