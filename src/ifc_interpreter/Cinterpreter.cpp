#include "StdAfx.h"
#include "Creceiver.h"
#include "Cinterpreter.h"
#include "unicodeReader.h"

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
	//для универсальности
}


int Cinterpreter::m_getWall(void)
{
	int ItemCount = 0;
	SdaiIterator NodeIterator = sdaiextGetExtentIterator(m_STEPModel, "IfcWallStandardCase");

	while(SdaiInstance STEPNodeInstance = sdaiextGetInstanceByIterator(NodeIterator))
	{
		SdaiInstance ObjectPlacementInstance = NULL;
		sdaiGetAttrBN(STEPNodeInstance, "ObjectPlacement", sdaiINSTANCE, &ObjectPlacementInstance);
		SdaiInstance RelativePlacementInstance = NULL;
		sdaiGetAttrBN(ObjectPlacementInstance, "RelativePlacement", sdaiINSTANCE, &RelativePlacementInstance);
		SdaiInstance LocationInstance = NULL;
		SdaiReal Coords [3] = {0.0, 0.0, 0.0};//координаты начальной точки
		sdaiGetAttrBN(RelativePlacementInstance, "Location", sdaiINSTANCE, &LocationInstance);

		if( LocationInstance )
		{
			SdaiIterator CoordIterator = sdaiextGetAttributeIterator(LocationInstance, "Coordinates");
			sdaiBeginning(CoordIterator);
			sdaiNext(CoordIterator);
			sdaiGetAggrByIterator(CoordIterator, sdaiREAL, &Coords [0]);
			sdaiNext(CoordIterator);
			sdaiGetAggrByIterator(CoordIterator, sdaiREAL, &Coords [1]);
			sdaiNext(CoordIterator);
			sdaiGetAggrByIterator(CoordIterator, sdaiREAL, &Coords [2]);
			sdaiDeleteIterator(CoordIterator);
		}
		//направление
		SdaiInstance RefDirectionInstance = NULL;
		SdaiReal Directions [2] = {1.0, 0.0};
		sdaiGetAttrBN(RelativePlacementInstance, "RefDirection", sdaiINSTANCE, &RefDirectionInstance);

		if( RefDirectionInstance )
		{
			SdaiIterator DirectionIterator = sdaiextGetAttributeIterator(RefDirectionInstance, "DirectionRatios");
			sdaiBeginning(DirectionIterator);
			sdaiNext(DirectionIterator);
			sdaiGetAggrByIterator(DirectionIterator, sdaiREAL, &Directions [0]);
			sdaiNext(DirectionIterator);
			sdaiGetAggrByIterator(DirectionIterator, sdaiREAL, &Directions [1]);
			sdaiDeleteIterator(DirectionIterator);
		}
		// sdaiNext(NodeIterator);

		SdaiInstance RepresentationInstance = NULL;
		sdaiGetAttrBN(STEPNodeInstance, "Representation", sdaiINSTANCE, &RepresentationInstance);
		SdaiIterator RepresentationIterator = sdaiextGetAttributeIterator(RepresentationInstance, "Representations");
		sdaiBeginning(RepresentationIterator);
		sdaiNext(RepresentationIterator);
		sdaiNext(RepresentationIterator);
		SdaiInstance ShapeRepresentationInstance=0;
		sdaiGetAggrByIterator(RepresentationIterator, sdaiINSTANCE, &ShapeRepresentationInstance);
		SdaiIterator ItemsIterator = sdaiextGetAttributeIterator(ShapeRepresentationInstance, "Items");
		sdaiBeginning(ItemsIterator);
		sdaiNext(ItemsIterator);
		SdaiInstance ExtrudedAreaInstance=0;
		sdaiGetAggrByIterator(ItemsIterator, sdaiINSTANCE, &ExtrudedAreaInstance);
		SdaiInstance SweptAreaInstance = NULL;
		sdaiGetAttrBN(ExtrudedAreaInstance, "SweptArea", sdaiINSTANCE, &SweptAreaInstance);
		SdaiReal Length = 0.0;
		sdaiGetAttrBN(SweptAreaInstance, "XDim", sdaiREAL, &Length);//длина

		sdaiDeleteIterator(ItemsIterator);
		sdaiDeleteIterator(RepresentationIterator);
		ItemCount++;

	}
	sdaiDeleteIterator(NodeIterator);
	return ItemCount;
}

int Cinterpreter::m_getStorey(void)
{
	//этаж
	return 0;
}
