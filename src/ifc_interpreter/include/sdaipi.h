#ifndef _SDAIPI_
#define _SDAIPI_
//
#pragma pack (push, 8)
//
CRPSDAIEXTERNAL
SdaiInstance sdaipiAddSubtypeInstance
 (SdaiInstance OriginalInstance, 
 SdaiModel Model, 
 SdaiEntity Entity);
//
CRPSDAIEXTERNAL
SdaiInstance sdaipiAddSubtypeInstanceBN
 (SdaiInstance OriginalInstance, 
 SdaiModel Model, 
 SdaiString EntityName);
//
CRPSDAIEXTERNAL
SdaiInstance sdaipiAddSupertypeInstance
 (SdaiInstance OriginalInstance, 
 SdaiModel Model, 
 SdaiEntity Entity);
//
CRPSDAIEXTERNAL
SdaiInstance sdaipiAddSupertypeInstanceBN
 (SdaiInstance OriginalInstance, 
 SdaiModel Model, 
 SdaiString EntityName);
//
CRPSDAIEXTERNAL
void sdaipiRemoveInstance
 (SdaiInstance Instance);
//
CRPSDAIEXTERNAL
bool sdaipiReplaceWithSubtypeInstance
 (SdaiInstance OriginalInstance, 
 SdaiModel Model, 
 SdaiEntity Entity);
//
CRPSDAIEXTERNAL
bool sdaipiReplaceWithSubtypeInstanceBN
 (SdaiInstance OriginalInstance, 
 SdaiModel Model, 
 SdaiString EntityName);
//
CRPSDAIEXTERNAL
bool sdaipiReplaceWithSupertypeInstance
 (SdaiInstance OriginalInstance, 
 SdaiModel Model, 
 SdaiEntity Entity);
//
CRPSDAIEXTERNAL
bool sdaipiReplaceWithSupertypeInstanceBN
 (SdaiInstance OriginalInstance, 
 SdaiModel Model, 
 SdaiString EntityName);
#pragma pack (pop)
#endif /* SDAI PI */