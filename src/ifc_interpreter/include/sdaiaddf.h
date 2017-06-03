//
//
#ifndef _SDAIADDH_H_
#define _SDAIADDH_H_
//
#pragma pack (push, 8)
//
CRPSDAIEXTERNAL
SdaiNPL GetAllSupertypes
 (SdaiEntity Entity);
CRPSDAIEXTERNAL
SdaiNPL GetAllAttributeDefinitions
 (SdaiEntity Entity,
 BOOL AddExplicitAttributes,
 BOOL AddInverseAttributes,
 BOOL AddDerivedAttributes,
 BOOL ReferencesOnly);
CRPSDAIEXTERNAL
SdaiNPL GetAllAttributeDefinitions
 (SdaiEntity Entity,
 BOOL AddExplicitAttributes,
 BOOL AddInverseAttributes,
 BOOL AddDerivedAttributes);
CRPSDAIEXTERNAL
void GetAttributeDefinitions
 (SdaiEntity Entity,
 SdaiNPL ListOfAttributes,
 BOOL AddExplicitAttributes,
 BOOL AddInverseAttributes,
 BOOL AddDerivedAttributes,
 BOOL ReferencesOnly);
CRPSDAIEXTERNAL
void GetAttributeDefinitions
 (SdaiEntity Entity,
 SdaiNPL ListOfAttributes,
 BOOL AddExplicitAttributes,
 BOOL AddInverseAttributes,
 BOOL AddDerivedAttributes);
CRPSDAIEXTERNAL
SdaiPrimitiveType FindTerminalDomain
 (SdaiInstance Domain, SdaiBoolean FindReferences);
CRPSDAIEXTERNAL
SdaiBoolean IsMemberIncludingNested
 (SdaiAggr Aggregate,SdaiInstance Instance);
CRPSDAIEXTERNAL
SdaiNPL GetAllInstancesOfSchemaInstance
 (SdaiSchemaInstance SchemaInstance);
CRPSDAIEXTERNAL
BOOL RefreshRepository
 (SdaiRep Repository);
CRPSDAIEXTERNAL
SdaiNPL GetComponentsOfComplexEntity
 (SdaiEntity Entity);
CRPSDAIEXTERNAL
SdaiNPL GetNamesOfComplexEntity
 (SdaiEntity Entity);
CRPSDAIEXTERNAL
 void InitCommonNPL();
CRPSDAIEXTERNAL
 void ClearCommonNPL();
CRPSDAIEXTERNAL
void SetWorkPath
 (char* NewPath);
CRPSDAIEXTERNAL
BOOL SaveRepositoryBN
 (SdaiString SavedRepositoryName);
CRPSDAIEXTERNAL
 SdaiNPL GetListOfSchemaInstances
  (SdaiRep Repository);
CRPSDAIEXTERNAL
 SdaiNPL GetListOfSDAIModels
  (SdaiRep Repository);
CRPSDAIEXTERNAL
 SdaiInstance GetDefinedType
  (SdaiSchema Schema, SdaiString TypeName);
CRPSDAIEXTERNAL
 SdaiADB CreateSelectADB
  (SdaiInstance DefinedType, SdaiADB ADBWithValue);
CRPSDAIEXTERNAL
int RemoveItemFromAggregate
 (BOOL Repeate,SdaiAggr Aggregate,SdaiPrimitiveType valueType,...);
CRPSDAIEXTERNAL
SdaiNPL GetSchemaeList
 ();
CRPSDAIEXTERNAL
SdaiSchemaInstance GetAppSchemaInstance
 (SdaiString schemaInstanceName,SdaiRep repository);
CRPSDAIEXTERNAL
SdaiInstance AddEntityExtent
 (SdaiModel Model, SdaiEntity Entity);
CRPSDAIEXTERNAL
SdaiInteger GetCommonFISize
 ();
CRPSDAIEXTERNAL
SdaiInteger GetRepositorySize
 (SdaiRep Repository);
CRPSDAIEXTERNAL
void SetRTDSswappingLimit
 (int PageCounter);
CRPSDAIEXTERNAL
void SetRepositorySwappingLimit
 (SdaiRep Repository, int PageCounter);
CRPSDAIEXTERNAL
void SetRepositorySwappingLimitBN
 (SdaiString RepositoryName, int PageCounter);
CRPSDAIEXTERNAL
SdaiIterator sdaiextGetExtentIterator
 (SdaiModel Model, SdaiString EntityName, bool Direction = true);
CRPSDAIEXTERNAL
SdaiIterator sdaiextGetAttributeIterator 
 (SdaiInstance Instance, SdaiString AttributeName, bool Direction = true );
CRPSDAIEXTERNAL
SdaiInstance sdaiextGetInstanceByIterator
 (SdaiIterator Iterator, bool Direction = true );
CRPSDAIEXTERNAL
SdaiString sdaiextGetStringByIterator 
 (SdaiIterator Iterator, bool Direction = true );
CRPSDAIEXTERNAL
void sdaiextReleaseRepositoryMemory
 ();
CRPSDAIEXTERNAL
SdaiModel CreateModelInClonedRepository
 (SdaiModel Model, SdaiRep& Repository);
//
#pragma pack (pop)
#endif /*_SDAIADDH_H_*/
