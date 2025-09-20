#pragma once

#ifdef SPN_PLATFORM_WINDOWS
	#ifdef SPN_BUILD_DLL
		#define SIPHON_API __declspec(dllexport)
	#else
		#define SIPHON_API __declspec(dllimport)
	#endif
#else
	#error Siphon only supports Windows!
#endif