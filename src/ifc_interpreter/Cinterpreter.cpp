#include "StdAfx.h"
#include "Creceiver.h"
#include "Cinterpreter.h"
#include "unicodeReader.h"
#include "ifcTranslator.h"

Cinterpreter::Cinterpreter(void)
{
}


Cinterpreter::~Cinterpreter(void)
{
}


int Cinterpreter::m_getProjects()
{
	int Count = 0;
	SdaiIterator ProjectIterator = sdaiextGetExtentIterator(m_STEPModel, "IfcProject");
	while (SdaiInstance IFCProjectInstance = sdaiextGetInstanceByIterator(ProjectIterator))
	{
		Count++;
		m_getProject(IFCProjectInstance);
	}
	sdaiCloseSession(m_STEPSession);
	return Count;
}

int Cinterpreter::m_getBuilding(void)
{
	return true;
}
int Cinterpreter::m_getProject(SdaiInstance &IFCProjectInstance)
{
	if(IFCProjectInstance)
	{
		/*if (m_Receiver && m_Receiver->m_Function)
		m_Receiver->m_Function;*/
		// SdaiIterator RootIterator = sdaiextGetExtentIterator(m_STEPModel, "IfcRoot");

		SdaiString Str = nullptr;

		sdaiGetAttrBN(IFCProjectInstance, "Name", sdaiSTRING, &Str);
		Str = UnicodeRead(Str);

		m_Receiver->m_Function(Str);

		int WallsCount = m_getWall();

	}


	return 0;
}


int Cinterpreter::m_getSite(void)
{
	return 0;
	//��� ���������������
}


int Cinterpreter::m_getWall(void)
{
	int ItemCount = 0;
	SdaiIterator WallIterator = sdaiextGetExtentIterator(m_STEPModel, "IfcWallStandardCase");

	while(SdaiInstance STEPWallInstance = sdaiextGetInstanceByIterator(WallIterator))
	{
		CifcWallSweptSolid *Wall = new CifcWallSweptSolid;
		SdaiInstance ObjectPlacementInstance = NULL;
		sdaiGetAttrBN(STEPWallInstance, "ObjectPlacement", sdaiINSTANCE, &ObjectPlacementInstance);
		SdaiInstance RelativePlacementInstance = NULL;
		sdaiGetAttrBN(ObjectPlacementInstance, "RelativePlacement", sdaiINSTANCE, &RelativePlacementInstance);
		SdaiInstance LocationInstance = NULL;
		//SdaiReal Coords [3] = {0.0, 0.0, 0.0};//���������� ��������� �����
		sdaiGetAttrBN(RelativePlacementInstance, "Location", sdaiINSTANCE, &LocationInstance);

		if( LocationInstance )
		{
			SdaiIterator CoordIterator = sdaiextGetAttributeIterator(LocationInstance, "Coordinates");
			sdaiBeginning(CoordIterator);
			sdaiNext(CoordIterator);
			sdaiGetAggrByIterator(CoordIterator, sdaiREAL, &Wall->startCoordinates.x);
			sdaiNext(CoordIterator);
			sdaiGetAggrByIterator(CoordIterator, sdaiREAL, &Wall->startCoordinates.y);
			sdaiNext(CoordIterator);
			sdaiGetAggrByIterator(CoordIterator, sdaiREAL, &Wall->startCoordinates.z);
			sdaiDeleteIterator(CoordIterator);
		}
		//�����������
		SdaiInstance RefDirectionInstance = NULL;
		sdaiGetAttrBN(RelativePlacementInstance, "RefDirection", sdaiINSTANCE, &RefDirectionInstance);

		if( RefDirectionInstance )
		{
			SdaiIterator DirectionIterator = sdaiextGetAttributeIterator(RefDirectionInstance, "DirectionRatios");
			sdaiBeginning(DirectionIterator);
			sdaiNext(DirectionIterator);
			sdaiGetAggrByIterator(DirectionIterator, sdaiREAL, &Wall->wallDirection[0]);
			sdaiNext(DirectionIterator);
			sdaiGetAggrByIterator(DirectionIterator, sdaiREAL, &Wall->wallDirection[1]);
			sdaiDeleteIterator(DirectionIterator);
		}
		// sdaiNext(WallIterator);

		SdaiInstance RepresentationInstance = NULL;
		sdaiGetAttrBN(STEPWallInstance, "Representation", sdaiINSTANCE, &RepresentationInstance);
		SdaiIterator RepresentationIterator = sdaiextGetAttributeIterator(RepresentationInstance, "Representations");
		SdaiList Representations;
		sdaiGetAttrBN(RepresentationInstance, "Representations", sdaiAGGR, &Representations);
		
		sdaiAppend(Representations, sdaiREAL, 1.0);
		sdaiBeginning(RepresentationIterator);
		sdaiNext(RepresentationIterator);
		sdaiNext(RepresentationIterator);

		SdaiInstance ShapeRepresentationInstance = 0;
		sdaiGetAggrByIterator(RepresentationIterator, sdaiINSTANCE, &ShapeRepresentationInstance);
		SdaiString RepType;
		sdaiGetAttrBN(ShapeRepresentationInstance, "RepresentationType", sdaiSTRING, &RepType); 

		if ( RepType = "SweptSolid" )
		{
		SdaiIterator ItemsIterator = sdaiextGetAttributeIterator(ShapeRepresentationInstance, "Items");
		sdaiBeginning(ItemsIterator);
		sdaiNext(ItemsIterator);
		SdaiInstance ExtrudedAreaInstance=0;
		sdaiGetAggrByIterator(ItemsIterator, sdaiINSTANCE, &ExtrudedAreaInstance);
		SdaiInstance SweptAreaInstance = NULL;

		sdaiGetAttrBN(ExtrudedAreaInstance, "Depth", sdaiREAL,  &Wall->wallHeight);
		sdaiGetAttrBN(ExtrudedAreaInstance, "SweptArea", sdaiINSTANCE, &SweptAreaInstance);
		sdaiGetAttrBN(SweptAreaInstance, "XDim", sdaiREAL, &Wall->wallLength);//�����
		sdaiGetAttrBN(SweptAreaInstance, "YDim", sdaiREAL, &Wall->wallWidth);

		sdaiDeleteIterator(ItemsIterator);
		sdaiDeleteIterator(RepresentationIterator);
		ItemCount++;

		std::vector<Face> WallFaces = Wall->getFaces();

		createBrepWall(RepresentationInstance, WallFaces);

	/*sdaiSaveModelBN(m_STEPModel, m_ifcName);*/
		}
	}
	sdaiDeleteIterator(WallIterator);


	return ItemCount;
}

int Cinterpreter::m_getStorey(void)
{
	//����
	return 0;
}
