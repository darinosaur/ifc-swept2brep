#include "StdAfx.h"
#include "CifcWallSweptSolid.h"


CifcWallSweptSolid::CifcWallSweptSolid(void)
{
	this->wallDirection[0] = 1.0; 
	this->wallDirection[1] = 0.0;
	this->wallEdgeType = "Rectangle";
}


CifcWallSweptSolid::~CifcWallSweptSolid(void)
{
}

//std::vector<Face> CifcWallSweptSolid::getFaces()
//{
//
//
//}