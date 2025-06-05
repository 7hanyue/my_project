#pragma once

#if defined(WIN32) || defined (WIN64)
	#ifdef EGMServer_Plugin
		#define EGMServerExport __declspec(dllexport)
	#else
		#define EGMServerExport __declspec(dllimport)
	#endif
#else
	#ifndef EGMServerExport
		#define EGMServerExport
	#endif
#endif
