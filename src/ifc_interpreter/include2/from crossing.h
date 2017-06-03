//
#include "adbe.h"
#ifndef __FROMCROSSING__
#define __FROMCROSSING__
//
#pragma pack (push, 8)
//
 STEPKITEXTERNAL
SdaiSession STEPStart
 ();
 STEPKITEXTERNAL
SdaiSession STEPInit
 ();
 STEPKITEXTERNAL
void STEPSetWorkPath
 (char* NewPath);
 STEPKITEXTERNAL
void STEPSetWorkPath
 (char* NewPath);
 STEPKITEXTERNAL
bool STEPGenXF
 (SdaiString XFFileName,SdaiSchemaInstance SchemaInstance);
 STEPKITEXTERNAL
bool STEPGenXF
 (SdaiString XFileName, SdaiString SchemaName, SdaiNPL ListOfInstances);
 STEPKITEXTERNAL
void SetOriginatingSystemName
 (SdaiString Name);
 STEPKITEXTERNAL
void SetUserName
 (SdaiString Name);
 STEPKITEXTERNAL
void SetOrganizationName
 (SdaiString Name);
 STEPKITEXTERNAL
void SetConverterName
 (SdaiString Name);
 STEPKITEXTERNAL
void SetModelName
 (SdaiString Name);
 STEPKITEXTERNAL
SdaiModel GetHeaderModel
 ();
 STEPKITEXTERNAL
SdaiSchemaInstance GetHeaderSchemaInstance
 ();
 STEPKITEXTERNAL
CADB* GetListOfInstances
 ();
//
SdaiString STEPGetUnderlyingSchemaName
 (SdaiSchemaInstance SchemaInstance);
long STEPPrepareListOfInstances
 (SdaiNPL ListOfInstances);
long STEPAssignEntityDefinitions
 ();
long STEPAssignIdInExchangeFile
 (long IdInExchangeFile=0);
bool WriteXF
 (char* OriginalXFileName,SdaiString SchemaName);
void InitNames
 ();
//
//  WriteXF
//
char* CutFileNamePath
 (char* OriginalFileName);
//
bool STEPWriteAggregate
 (long Scope,SdaiAggr Aggregate,long Attribute);
//
// STEP XF utilities
//
long LoadAttribute
 (SdaiEntity BaseType);
//
void* STEPGetAttribute
 (long Id);
//
void* STEPFindEntity
 (SdaiEntity Entity, SdaiEntity BaseEntity = 0);
//
long STEPCreateEmptyAttribute
 ();
//
SdaiPrimitiveType DefineType
 (SdaiEntity BaseType);
//
 STEPKITEXTERNAL
void STEPDelete
 ();
long STEPGetReferedIdInExchangeFile
 (SdaiInstance Instance,SdaiInteger Scope);
//
void WriteReal
 (SdaiReal Value);
//
void WriteBoolean
 (SdaiBoolean Value);
//
void WriteLogical
 (SdaiLogical Value);
//
void WriteLineFeed
 (int Size, bool LastLine = false);
//
void WriteItem
 (char* Item, bool LastLine = false);
//
void WriteInteger
 (SdaiInteger Value);
//
void WriteString
 (SdaiString Value);
//
void WriteEnum
 (SdaiEnum Value);
//
void WriteInstance
 (SdaiInstance Value);
//
void WriteBinary
 (SdaiBinary Value);
//
#pragma pack (pop)
#endif