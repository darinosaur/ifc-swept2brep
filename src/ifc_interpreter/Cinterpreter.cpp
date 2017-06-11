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
		SdaiString Str = nullptr;
		// testik
		// SdaiString Str = "\\X2\\042104420430044204430441\\X0\\ \\X2\\043F0440043E0435043A04420430\\X0\\";*/
		sdaiGetAttrBN(IFCProjectInstance, "Name", sdaiSTRING, &Str);
		
		Str = UnicodeRead(Str);

		m_Receiver->m_Function(Str);

		int WallsCount = m_getWall();
	}

	return 0;
}

int Cinterpreter::m_getSite(void)
{
	// для универсальности
	return 0;
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
		//направление
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
		sdaiGetAttrBN(SweptAreaInstance, "XDim", sdaiREAL, &Wall->wallLength);//длина
		sdaiGetAttrBN(SweptAreaInstance, "YDim", sdaiREAL, &Wall->wallWidth);

		sdaiDeleteIterator(ItemsIterator);
		sdaiDeleteIterator(RepresentationIterator);
		ItemCount++;

		std::vector<Face> WallFaces = Wall->getFaces();

	createBrepWall(RepresentationInstance, WallFaces, this); 
		}
	}
	sdaiDeleteIterator(WallIterator);

	int test = saveIFCFile(this);
	return ItemCount;
}

int Cinterpreter::m_getStorey(void)
{
	//этаж
	return 0;
}

void createBrepWall(SdaiInstance &RepresentationInstance, std::vector<Face> WallFaces, Cinterpreter *Interpreter)
{
	SdaiAggr RepresentationsAggr = -1;
	sdaiGetAttrBN(RepresentationInstance, "Representations", sdaiAGGR, &RepresentationsAggr ); 
	// Попробовали получить уже существующий агрегатный атрибут
	
	if( RepresentationsAggr  <= 0)
	{
		RepresentationsAggr = sdaiCreateAggrBN(RepresentationInstance, "Representations"); 
		// Если атрибута агрегатного не оказалось
	}
	SdaiInstance ShapeRepresentationInstance = sdaiCreateInstanceBN(Interpreter->m_STEPModel, "IfcShapeRepresentation"); 
	// Создался экземпляр того ентитя, который должен попасть в список
	sdaiAdd(RepresentationsAggr, sdaiINSTANCE, ShapeRepresentationInstance ); 

	SdaiAggr aggrItems = sdaiCreateAggrBN(ShapeRepresentationInstance, "Items");

	sdaiPutAttrBN(ShapeRepresentationInstance, "RepresentationIdentifier", sdaiSTRING, "Body");
	sdaiPutAttrBN(ShapeRepresentationInstance, "RepresentationType", sdaiSTRING, "Brep");
	sdaiPutAttrBN(ShapeRepresentationInstance, "ContextOfItems", sdaiINSTANCE, getGeometricRepresentationContextInstance(Interpreter));

	 SdaiInstance   ifcFacetedBrepInstance, ifcClosedShellInstance;
	 SdaiAggr aggrCfsFaces;

	 ifcClosedShellInstance = sdaiCreateInstanceBN(Interpreter->m_STEPModel, "IFCCLOSEDSHELL");
	 aggrCfsFaces = sdaiCreateAggrBN(ifcClosedShellInstance, "CfsFaces");

	 SdaiInstance ifcPolyLoopInstance, ifcFaceOuterBoundInstance, ifcFaceInstance;
	 SdaiAggr aggrPolygon, aggrBounds;
}

int saveIFCFile(Cinterpreter* Interpreter)
{
	CString HealedFileName = "C:\\constrData\\constructionData\\etoSTENY5.ifc";
	STEPGenXF(HealedFileName.GetBuffer(), Interpreter->m_STEPSchemaInstance);

	return -2;
}

SdaiInstance createFace(std::vector<Face> FaceSet)
{
	SdaiInstance CfsFaceInstance;

return CfsFaceInstance;
}

SdaiInstance createCartesianPoint(Point3d *P, Cinterpreter *Interpreter)
{
	SdaiInstance ifcCartesianPointInstance;
	SdaiAggr aggrCoordinates;

	ifcCartesianPointInstance = sdaiCreateInstanceBN(Interpreter->m_STEPModel, "IFCCARTESIANPOINT");

	aggrCoordinates = sdaiCreateAggrBN(ifcCartesianPointInstance, "Coordinates");
	sdaiAppend((int) aggrCoordinates, sdaiREAL, &P->x);
	sdaiAppend((int) aggrCoordinates, sdaiREAL, &P->y);
	sdaiAppend((int) aggrCoordinates, sdaiREAL, &P->z);

	return	ifcCartesianPointInstance;
}

SdaiInstance getGeometricRepresentationContextInstance(Cinterpreter *Interpreter)
{
    SdaiInstance ifcGeometricRepresentationContextInstance;
    double  precision = 0.00001;
    int     coordinateSpaceDimension = 3;

	ifcGeometricRepresentationContextInstance = sdaiCreateInstanceBN(Interpreter->m_STEPModel, "IFCGEOMETRICREPRESENTATIONCONTEXT");

	sdaiPutAttrBN(ifcGeometricRepresentationContextInstance, "ContextType", sdaiSTRING, "Model");
	sdaiPutAttrBN(ifcGeometricRepresentationContextInstance, "CoordinateSpaceDimension", sdaiINTEGER, &coordinateSpaceDimension);
	sdaiPutAttrBN(ifcGeometricRepresentationContextInstance, "Precision", sdaiREAL, &precision);
	// sdaiPutAttrBN(ifcGeometricRepresentationContextInstance, "WorldCoordinateSystem", sdaiINSTANCE, (void*) getWorldCoordinateSystemInstance());

    return  ifcGeometricRepresentationContextInstance;
}
