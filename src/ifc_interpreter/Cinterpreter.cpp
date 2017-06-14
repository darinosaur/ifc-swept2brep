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

		int WallsCount = m_getWall(); 

		//Str = Str + (char)(WallsCount);
		m_Receiver->m_Function(Str);

		
	}

	return 0;
}

int Cinterpreter::m_getSite(void)
{
	// ��� ���������������
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
		
		
		sdaiBeginning(RepresentationIterator);

		SdaiInstance ShapeRepresentationInstance = 0;

		sdaiNext(RepresentationIterator);

		sdaiNext(RepresentationIterator);

		
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
		
			if (sdaiIsKindOfBN(SweptAreaInstance,"IfcRectangleProfileDef"))
			{
				sdaiGetAttrBN(SweptAreaInstance, "XDim", sdaiREAL, &Wall->wallLength);//�����
				sdaiGetAttrBN(SweptAreaInstance, "YDim", sdaiREAL, &Wall->wallWidth);

				sdaiDeleteIterator(ItemsIterator);
				sdaiDeleteIterator(RepresentationIterator);
				ItemCount++;

				std::vector<Face> WallFaces = Wall->getFaces();

				createBrepWall(RepresentationInstance, WallFaces, this); 
			}
			//else 
				// AdvancedBrep)))))))000000
		}
	}
	sdaiDeleteIterator(WallIterator);

	int test = saveIFCFile(this);
	return ItemCount;
}

int Cinterpreter::m_getStorey(void)
{
	//����
	return 0;
}

void createBrepWall(SdaiInstance &RepresentationInstance, std::vector<Face> WallFaces, Cinterpreter *Interpreter)
{
	SdaiAggr RepresentationsAggr = -1;
	sdaiGetAttrBN(RepresentationInstance, "Representations", sdaiAGGR, &RepresentationsAggr ); 
	// ����������� �������� ��� ������������ ���������� �������
	
	if( RepresentationsAggr  <= 0)
	{
		RepresentationsAggr = sdaiCreateAggrBN(RepresentationInstance, "Representations"); 
		// ���� �������� ����������� �� ���������
	}
	SdaiInstance ShapeRepresentationInstance = sdaiCreateInstanceBN(Interpreter->m_STEPModel, "IfcShapeRepresentation"); 
	// �������� ��������� ���� ������, ������� ������ ������� � ������
	sdaiAdd(RepresentationsAggr, sdaiINSTANCE, ShapeRepresentationInstance ); 

	SdaiAggr aggrItems = sdaiCreateAggrBN(ShapeRepresentationInstance, "Items");

	sdaiPutAttrBN(ShapeRepresentationInstance, "RepresentationIdentifier", sdaiSTRING, "Body");
	sdaiPutAttrBN(ShapeRepresentationInstance, "RepresentationType", sdaiSTRING, "Brep");
	sdaiPutAttrBN(ShapeRepresentationInstance, "ContextOfItems", sdaiINSTANCE, getGeometricRepresentationContextInstance(Interpreter));

	 SdaiInstance   ifcFacetedBrepInstance, ifcClosedShellInstance;
	 SdaiAggr aggrCfsFaces;

	 ifcClosedShellInstance = sdaiCreateInstanceBN(Interpreter->m_STEPModel, "IFCCLOSEDSHELL");
	 aggrCfsFaces = sdaiCreateAggrBN(ifcClosedShellInstance, "CfsFaces");

	 for( int i = 0;i < WallFaces.size() ; i++) // faces counter
	 {
		SdaiInstance ifcFaceInstance = createFaceInstance(WallFaces, Interpreter, i);
		sdaiAdd(aggrCfsFaces, sdaiINSTANCE, ifcFaceInstance ); 
	 }

	 
	ifcFacetedBrepInstance = sdaiCreateInstanceBN(Interpreter->m_STEPModel, "IFCFACETEDBREP");
	sdaiPutAttrBN(ifcFacetedBrepInstance, "Outer", sdaiINSTANCE, ifcClosedShellInstance);
	
    sdaiAppend(aggrItems, sdaiINSTANCE, ifcFacetedBrepInstance);
}

int saveIFCFile(Cinterpreter* Interpreter)
{
	CString HealedFileName = (CString)Interpreter->m_ifcName;
	STEPGenXF(HealedFileName.GetBuffer(), Interpreter->m_STEPSchemaInstance);

	return -2;
}

SdaiInstance createFaceInstance(std::vector<Face> FaceSet, Cinterpreter* Interpreter, int faceNum)
{
	SdaiInstance ifcPolyLoopInstance = createPolyLoop(Interpreter, FaceSet, faceNum); 
	
	SdaiInstance ifcFaceOuterBoundInstance = sdaiCreateInstanceBN(Interpreter->m_STEPModel, "IFCFACEOUTERBOUND");
	    sdaiPutAttrBN(ifcFaceOuterBoundInstance, "Bound", sdaiINSTANCE, ifcPolyLoopInstance);
        sdaiPutAttrBN(ifcFaceOuterBoundInstance, "Orientation", sdaiENUM, "T");

	SdaiInstance ifcFaceInstance = sdaiCreateInstanceBN(Interpreter->m_STEPModel, "IfcFace"); 
	

	SdaiAggr aggrBounds = sdaiCreateAggrBN(ifcFaceInstance, "Bounds");
	    sdaiAppend((int) aggrBounds, sdaiINSTANCE, ifcFaceOuterBoundInstance);

		

return ifcFaceInstance;
}

SdaiInstance createPolyLoop(Cinterpreter* Interpreter, std::vector<Face> FaceSet, int faceNum)
{

	std::vector<SdaiInstance> ifcPointInstances;

	SdaiInstance ifcPolyLoopInstance;
	ifcPolyLoopInstance = sdaiCreateInstanceBN(Interpreter->m_STEPModel, "IFCPOLYLOOP");
	SdaiAggr  aggrPolygon = sdaiCreateAggrBN(ifcPolyLoopInstance, "Polygon");

	
	ifcPointInstances.push_back(createCartesianPoint(&FaceSet[faceNum].P1, Interpreter));
		sdaiAppend((int) aggrPolygon, sdaiINSTANCE, ifcPointInstances[0]);
		
		ifcPointInstances.push_back(createCartesianPoint(&FaceSet[faceNum].P2, Interpreter));
		sdaiAppend((int) aggrPolygon, sdaiINSTANCE, ifcPointInstances[1]);
		
		ifcPointInstances.push_back(createCartesianPoint(&FaceSet[faceNum].P3, Interpreter));
		sdaiAppend((int) aggrPolygon, sdaiINSTANCE, ifcPointInstances[2]);


	return ifcPolyLoopInstance;
}

SdaiInstance createCartesianPoint(Point3d *P, Cinterpreter *Interpreter)
{
	SdaiInstance ifcCartesianPointInstance;
	SdaiAggr aggrCoordinates;

	ifcCartesianPointInstance = sdaiCreateInstanceBN(Interpreter->m_STEPModel, "IFCCARTESIANPOINT");

	aggrCoordinates = sdaiCreateAggrBN(ifcCartesianPointInstance, "Coordinates");
	sdaiAppend(aggrCoordinates, sdaiREAL, P->x);
	sdaiAppend(aggrCoordinates, sdaiREAL, P->y);
	sdaiAppend(aggrCoordinates, sdaiREAL, P->z);

	return	ifcCartesianPointInstance;
}

SdaiInstance getWorldCoordinateSystemInstance(Cinterpreter *Interpreter)
{
    Point3d point;
	point.x = 0;
	point.y = 0;
	point.z = 0;

	SdaiInstance ifcWorldCoordinateSystemInstance = sdaiCreateInstanceBN(Interpreter->m_STEPModel, "IFCAXIS2PLACEMENT3D");
    sdaiPutAttrBN(ifcWorldCoordinateSystemInstance, "Location", sdaiINSTANCE, createCartesianPoint(&point, Interpreter));

    return ifcWorldCoordinateSystemInstance;
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
	sdaiPutAttrBN(ifcGeometricRepresentationContextInstance, "WorldCoordinateSystem", sdaiINSTANCE, getWorldCoordinateSystemInstance(Interpreter));

    return  ifcGeometricRepresentationContextInstance;
}
