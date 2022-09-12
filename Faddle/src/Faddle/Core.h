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