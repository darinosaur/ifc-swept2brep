#pragma once
#include "Creceiver.h"
#include "CifcWallSweptSolid.h"

class Cinterpreter
{
public:
	Cinterpreter(void);
	~Cinterpreter(void);
	SdaiSession m_STEPSession;
	SdaiModel m_STEPModel;
	SdaiSchemaInstance m_STEPSchemaInstance; 
	SdaiModel m_HeaderModel;
	Creceiver *m_Receiver;
	
	int IFCWALKER_EXTERNAL   m_getProjects();
	int IFCWALKER_EXTERNAL   m_getProject(SdaiInstance &Instance);
	int IFCWALKER_EXTERNAL   m_getSite(void);
	int IFCWALKER_EXTERNAL   m_getBuilding(void);
	int IFCWALKER_EXTERNAL   m_getWall(void);
	int IFCWALKER_EXTERNAL   m_getStorey(void);
};


