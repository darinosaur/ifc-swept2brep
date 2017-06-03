//
#ifndef __STEPKITpdm__
#define __STEPKITpdm__
//
#pragma pack (push, 8)
//
STEPKITEXTERNAL
bool STEPIsId
 (SdaiInstance Instance, SdaiString Id);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiNPL STEPFindSDRs
 (SdaiSchemaInstance SchemaInstance, SdaiString ProductId = NULL);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCopyPDF
 (SdaiModel Model, SdaiInstance PDF);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
void STEPDeletePDF
 (SdaiInstance PDF);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
void STEPDeleteProduct
 (SdaiInstance Product);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
void STEPDeleteProductContext
 (SdaiInstance ProductContext);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiInstance STEPCopyProduct
 (SdaiModel Model, SdaiInstance Product);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiNPL STEPFindProducts
 (SdaiSchemaInstance SchemaInstance);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiNPL STEPFindMFUOs
 (SdaiSchemaInstance SchemaInstance);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiNPL STEPFindACUs
 (SdaiSchemaInstance SchemaInstance);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiNPL STEPFindPPAs
 (SdaiSchemaInstance SchemaInstance, SdaiInstance TestInstance = 0);
//
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//=
STEPKITEXTERNAL
SdaiNPL STEPFindActions
 (SdaiSchemaInstance SchemaInstance);
//
#pragma pack (pop)
//
#endif
