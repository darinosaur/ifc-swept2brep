#pragma once
#include "CifcWallSweptSolid.h"


void createBrepWall(SdaiInstance &Instance, std::vector<Face> WallFaces);

SdaiInstance createFace(std::vector<Face> FaceSet);

SdaiInstance createCartesianPoint(Face F1, SdaiInstance &Instance);
