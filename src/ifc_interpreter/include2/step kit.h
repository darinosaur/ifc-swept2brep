//
#ifndef __STEPKIT__
#define __STEPKIT__
//
#pragma pack (push, 8)
//
 STEPKITEXTERNAL
long ReplaceReferences
 (SdaiModel Model, 
 SdaiInstance InitialReference, 
 SdaiInstance TargetReference);
//
 STEPKITEXTERNAL
void SetDiagnosticFunction
 (void (*InterfaceFunction)(int));
//
 STEPKITEXTERNAL
void SetDiagnosticModeFunction
 (void (*InterfaceFunction)(int));
//
 STEPKITEXTERNAL
void SetDiagnosticTotalCounterFunction
 (void (*InterfaceFunction)(int));
//
 STEPKITEXTERNAL
int GetDiagnosticStep
 ();
//
 STEPKITEXTERNAL
void SetDiagnosticStep000
 ();
//
 STEPKITEXTERNAL
void SetDiagnosticStep001
 ();
//
 STEPKITEXTERNAL
void SetDiagnosticStep010
 ();
//
 STEPKITEXTERNAL
void SetDiagnosticStep100
 ();
//
 STEPKITEXTERNAL
void SetDiagnosticStep1000
 ();
//
 STEPKITEXTERNAL
SdaiString STEPGetModelSchemaName
 (SdaiModel Model);
//
void STEPKitErrorHandler
 (int ErrorCode, SdaiInstance BadInstance, long Param);
//
#pragma pack (pop)
//
#endif
