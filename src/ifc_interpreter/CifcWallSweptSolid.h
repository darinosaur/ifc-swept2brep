#pragma once

#include <vector>
#include "Point3d.h"

class CifcWallSweptSolid
{
public:
	CifcWallSweptSolid(void);
	~CifcWallSweptSolid(void);

	//rectangleProfileDef
	SdaiReal wallLength;
	SdaiReal wallHeight;
	SdaiReal wallWidth;

	Point3d startCoordinates;
	SdaiReal wallDirection[2];
	SdaiString wallEdgeType;

	/*std::vector<Face> getFaces();*/

};

