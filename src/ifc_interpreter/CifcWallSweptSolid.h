#pragma once
class CifcWallSweptSolid
{
public:
	CifcWallSweptSolid(void);
	~CifcWallSweptSolid(void);

	SdaiReal wallLength;
	SdaiReal  wallHeight;
	SdaiReal  wallWidth;

	SdaiReal startCoordinates[3];
	SdaiReal wallDirection[2];
	SdaiString wallEdgeType;

};

