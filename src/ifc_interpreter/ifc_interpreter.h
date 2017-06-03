// ifc_interpreter.h : main header file for the ifc_interpreter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "Cinterpreter.h"
#include "IFCInterpreterInterface.h";
#include "Creceiver.h"

// Cifc_interpreterApp
// See ifc_interpreter.cpp for the implementation of this class
//

class Cifc_interpreterApp : public CWinApp
{
public:
	Cifc_interpreterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


//bool OpenRepository(char *IFCName);