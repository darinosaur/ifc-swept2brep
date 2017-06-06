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

std::vector<Face> CifcWallSweptSolid::getFaces()
{
	Point3d startPnt = this->startCoordinates;//начальная точка в глобальных координатах
	std::vector<Point3d> Vertices;
	std::vector<Face> FaceSet;

	Vertices.push_back(Point3d (0, -(this->wallWidth)/2, 0));
	Vertices.push_back(Point3d (0, (this->wallWidth)/2, 0));
	Vertices.push_back(Point3d (this->wallLength, (this->wallWidth)/2, 0));
	Vertices.push_back(Point3d (this->wallLength, -(this->wallWidth)/2, 0));

	Vertices.push_back(Point3d (0, -(this->wallWidth)/2, this->wallHeight));
	Vertices.push_back(Point3d (0, (this->wallWidth)/2, this->wallHeight));
	Vertices.push_back(Point3d (this->wallLength, (this->wallWidth)/2, this->wallHeight));
	Vertices.push_back(Point3d (this->wallLength, -(this->wallWidth)/2, this->wallHeight));

	for(int i = 0; i < Vertices.size(); i++)
	{
		Vertices[i] = Vertices[i] + startPnt;
	}
	
	Face F1 = {Vertices[0],Vertices[1],Vertices[2],Vertices[3]};
	FaceSet.push_back(F1);

	Face F2 = {Vertices[0],Vertices[1],Vertices[4],Vertices[5]};
	FaceSet.push_back(F2);

	Face F3 = {Vertices[1],Vertices[2],Vertices[5],Vertices[6]};
	FaceSet.push_back(F3);

	Face F4 = {Vertices[2],Vertices[3],Vertices[6],Vertices[7]};
	FaceSet.push_back(F4);

	Face F5 = {Vertices[0],Vertices[3],Vertices[4],Vertices[7]};
	FaceSet.push_back(F5);

	Face F6 = {Vertices[4],Vertices[5],Vertices[6],Vertices[7]};
	FaceSet.push_back(F6);

	return FaceSet;
}