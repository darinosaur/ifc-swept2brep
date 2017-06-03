#ifndef __STEPKITgeometry__
#define __STEPKITgeometry__
//
#pragma pack (push, 8)
//

STEPKITEXTERNAL
SdaiNPL STEPCreateGeometricCurveSet
 (SdaiModel Model);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreatePoint
 (SdaiModel Model,double X,double Y,double Z, int SpaceDimension = 3);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateLine
 (SdaiModel Model
 ,SdaiInstance Point, SdaiInstance Vec);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateVec
 (SdaiModel Model
 ,SdaiInstance Direction, double Magnitude );
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateDirection
 (SdaiModel Model
 ,double X,double Y,double Z);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateUnitDirection
 (SdaiModel Model
 ,double X,double Y,double Z);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateOrthogonalDirection
 (SdaiModel Model
 ,double X0,double Y0,double Z0);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreatePlane
 (SdaiModel Model
 ,SdaiInstance Axis2Placement3d);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateCircle
 (SdaiModel Model,double Radius
 ,SdaiInstance Axis2Placement3d);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateEllipse
 (SdaiModel Model,double MajorRadius,double MinorRadius
 ,SdaiInstance Axis2Placement3d);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateAxis2Placement3d
 (SdaiModel Model
 ,SdaiInstance Placement
 ,SdaiInstance Axis1, SdaiInstance Axis2);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateNamedInstanceBN
 (SdaiModel Model, SdaiString EntityTypeName);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateCompositeCurve
 (SdaiModel Model);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPAddSegmentToCompositeCurve
 (SdaiModel Model, SdaiInstance CompositeCurve,
 SdaiInstance Segment, SdaiBoolean Orientation);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateBoundedCurve
 (SdaiModel Model);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateConicalSurface
 (SdaiModel Model,SdaiInstance AxisPlacement,
 double Radius,double SemiAngle);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateCylindricalSurface
 (SdaiModel Model,SdaiInstance AxisPlacement,
 double Radius);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateSphericalSurface
 (SdaiModel Model,SdaiInstance AxisPlacement,
 double Radius);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateToroidalSurface
 (SdaiModel Model,SdaiInstance AxisPlacement,
 double MajorRadius,double MinorRadius);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateHyperbola
 (SdaiModel Model,SdaiInstance AxisPlacement,
 double SemiAxis,double SemiImagAxis);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateParabola
 (SdaiModel Model,SdaiInstance AxisPlacement,
 double FocalDist);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateRationalBSplineCurve
 (SdaiModel Model);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateVertex
 (SdaiModel Model,double X,double Y,double Z, int SpaceDimension = 3);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCreateOrientedEdge
 (SdaiModel Model,SdaiInstance Edge, bool Orientation = true);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
#pragma pack (pop)
//
#endif
