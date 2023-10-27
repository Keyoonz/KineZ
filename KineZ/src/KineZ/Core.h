#pragma once

#ifdef KZ_PLATFORM_WINDOWS
	#ifdef KZ_BUILD_DLL
		#define KINEZ_API __declspec(dllexport)
	#else
		#define KINEZ_API __declspec(dllimport)
	#endif // KZ_BUILD_DLL
#else
#error KineZ only supports Windows for now.
#endif KZ_PLATFORM_WINDOWS

