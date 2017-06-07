#include "stdafx.h"
#include "ifcTranslator.h"

void createBrepWall(SdaiInstance &Instance, std::vector<Face> WallFaces)
{
	/*SdaiInstance ShapeRepresentation;
	sdaiAppend(Instance, sdaiREAL, 1.0);*/
	//sdaiPutAttrBN(Instance, "ContextOfItems", sdaiINSTANCE, (void*) getGeometricRepresentationContextInstance());
	//SdaiAggr aggrItems = sdaiCreateAggrBN(ifcShapeRepresentationInstance, "Items");

	//sdaiPutAttrBN(ifcShapeRepresentationInstance, "RepresentationIdentifier", sdaiSTRING, "Body");
	//sdaiPutAttrBN(ifcShapeRepresentationInstance, "RepresentationType", sdaiSTRING, "AdvancedBrep");*/
	//sdaiPutAttrBN(ifcShapeRepresentationInstance, "ContextOfItems", sdaiINSTANCE, (void*) getGeometricRepresentationContextInstance());
}


SdaiInstance createFace(std::vector<Face> FaceSet)
{
	SdaiInstance CfsFaceInstance;

return CfsFaceInstance;
}

SdaiInstance createCartesianPoint(Face F1, SdaiInstance &Instance)
{
	SdaiInstance PolygonInstance;

	return PolygonInstance;
}
