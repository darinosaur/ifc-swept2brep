// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
#pragma once

// TODO: reference additional headers your program requires here
#define IFCInterpreterInterface  __declspec ( dllimport )
//#define IFCInterpreterInterface __clrcall   __declspec ( dllimport )

#define IFCWALKER_EXTERNAL       __declspec( dllexport )
#define CRPSDAIEXTERNAL   __declspec ( dllimport )

#include "sdai.h"