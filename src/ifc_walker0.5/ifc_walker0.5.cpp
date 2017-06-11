// ifc_walker0.5.cpp : main project file.

#include "stdafx.h"
#include <cstring>
#include <iostream>
#include "../ifc_interpreter/IFCInterpreterInterface.h";
#include "Form1.h"

using namespace ifc_walker05;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Form1 ^ frm1 = gcnew Form1();
	Application::Run(frm1);
	return 0;
}
