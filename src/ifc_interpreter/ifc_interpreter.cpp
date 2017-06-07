// ifc_interpreter.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "Creceiver.h"
#include "ifc_interpreter.h"

//#include "IFCInterpreterInterface.h";

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Cinterpreter *Interpreter = nullptr;
//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// Cifc_interpreterApp

BEGIN_MESSAGE_MAP(Cifc_interpreterApp, CWinApp)
END_MESSAGE_MAP()


// Cifc_interpreterApp construction

Cifc_interpreterApp::Cifc_interpreterApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only Cifc_interpreterApp object

Cifc_interpreterApp theApp;


// Cifc_interpreterApp initialization

BOOL Cifc_interpreterApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

bool OpenRepository(char *IFCName)
{
	int Pos = 0;
	for(Pos = 127; Pos > 0;Pos--)
	{
		if(IFCName[Pos] == '/')break;
		if(IFCName[Pos] == '\\')break;
		IFCName[Pos] = 0;
	}
	char STEPPath [128];
	memset(STEPPath,0,128);
	for(Pos = 0; Pos<127; Pos++)
		STEPPath[Pos] = IFCName[Pos];
	//
	STEPSetWorkPath(IFCName);
	SdaiSession STEPSession = STEPStart();
	if(STEPSession > 0)
	{
		Interpreter = new Cinterpreter;
		if(Interpreter)
		{
			Interpreter->m_STEPSession = STEPSession;
		}
		return true;
	}
	else
		return false;
}

int ReadSTEPFile(char *IFCName)
{
	// Interpreter = new Cinterpreter;
	CInvariantXFI* InvariantXFI = CreateInvariantXFIForRead(IFCName);
	Interpreter->m_ifcName = IFCName;

	//
	// Если файл удалось открыть:
	//
	if(InvariantXFI)
	{
		InvariantXFI->m_Repository = sdaiOpenRepositoryBN(Interpreter->m_STEPSession, "sdai00.rp");
		Interpreter->m_HeaderModel = InvariantXFI->m_ReadHeader();
		if ( Interpreter->m_HeaderModel > 0)
		{
			SdaiIterator Iterator = sdaiextGetExtentIterator(Interpreter->m_HeaderModel, "file_schema");
			while (SdaiInstance FileSchema = sdaiextGetInstanceByIterator(Iterator))
			{
				SdaiIterator NestedIterator = sdaiextGetAttributeIterator(FileSchema,"schema_identifiers");
				while(char* Description = sdaiextGetStringByIterator(NestedIterator))
				{
					CString SchemaNameString = Description; 
					SdaiSchema Schema = sdaiGetSchema(SchemaNameString.GetBuffer());
					if(Schema > 0)
					{
						InvariantXFI->m_ReadSchemaNameFromFile();
						SdaiModel Model = InvariantXFI->m_ReadXF();
						sdaiAccessModel(Model, sdaiRW);
						if (Model > 0) 
						{
							Interpreter->m_STEPModel = Model;
						}
					}
					else
					{
						SdaiModel Model = sdaiCreateModelBN(InvariantXFI->m_Repository,"imported","IFC4");
						InvariantXFI->m_CurrentSDAIModel = Model;
						Model = InvariantXFI->m_ReadXF();
						if (Model > 0) 
						{
							Interpreter->m_STEPModel = Model;
						}
						//хитрая проверка, потом
					}
				}

			} 

		}


		//
		// Завершение:
		//
		if(Interpreter->m_STEPModel)
		{
			SdaiSchema SchemaOfLoadedModel = 0;
			sdaiGetAttrBN
				(Interpreter->m_STEPModel,"underlying_schema", sdaiINSTANCE,&SchemaOfLoadedModel);
			Interpreter->m_STEPSchemaInstance = sdaiCreateSchemaInstance("S1", SchemaOfLoadedModel, InvariantXFI->m_Repository);
			sdaiAddModel(Interpreter->m_STEPSchemaInstance, Interpreter->m_STEPModel);
		}
		DeleteInvariantXFI(InvariantXFI);	
		//
		// Теперь надо заполнить список
		//
		//	m_FillNodeList();

		return 0;
	}
}

int getProjects(Creceiver *Receiver)
{
	int Count = 0;
	int Check = 0;
	if (Interpreter)
	{
		Interpreter->m_Receiver = Receiver;

		Count = Interpreter->m_getProjects();
		Check = Interpreter->m_getBuilding();
	}
	//возвращаем кол-во проектов (счетчик)
	return Count;
}

