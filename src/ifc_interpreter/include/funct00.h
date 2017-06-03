//
// FUNCT00.HPP
//
// Prototypes of CrpSDAI functions
//
#ifndef __FUNCT00_H
#define __FUNCT00_H
//
#include "sdai.h"
#include "sdaibase.h"
#include "sdaiadb.h"
#include <windows.h>
#include "sdaiaddf.h"
//
#pragma pack (push, 8)
//
//
   SdaiADB CreateNewADBStruct(NPLTypes Type);
   void DeleteADBStruct(SdaiADB block,ADBStruct* ADB,NPLTypes Type);
   BOOL ValidateADBStructId(long ADBid);
//
//
   int ValidateADBType(SdaiPrimitiveType ADBType);
   BOOL GetADBBody(SdaiADB block,ADBStruct* ADB);
   BOOL ReplaceADBBody(SdaiADB block,ADBStruct* ADB);
   BOOL ADBIsValid(SdaiADB ADB);
//
//
//
//
 void DeleteIterator(SdaiIterator iterator);
 void IncrementIterator(SdaiIterator iterator);
 void DecrementIterator(SdaiIterator iterator);
//
 BOOL IteratorIsValid(SdaiIterator Iterator);
//
 SdaiAggr GetAggregate(SdaiIterator iterator);
 SdaiAggrIndex GetIndex(SdaiIterator iterator);
 void SetIndex(SdaiIterator iterator,SdaiAggrIndex Index);
//
//
 SdaiNPL CreateNPL();
 void DeleteNPL(SdaiNPL NPLId);
 void DeleteAllADB(SdaiNPL NPLId);
 BOOL NPLIsValid(SdaiNPL NPL);
//
 BOOL NPLGet
  (SdaiNPL NPL,long Position,int Size,void* BulkData);
 BOOL NPLPut
  (SdaiNPL NPL,long Position,int Size,void* BulkData);
 BOOL NPLAdd
  (SdaiNPL NPL,long Position,int Size,void* BulkData=NULL);
//
 long GetNPLSize(SdaiNPL NPL);
//
 void MakeNPLEmpty(SdaiNPL NPLId);
 BOOL NPLGet
  (NPLBlock** First,NPLBlock** Current,
  long Position,int Size,void* BulkData);
 BOOL NPLPut
  (NPLBlock** First,NPLBlock** Current,
  long Position,int Size,void* BulkData);
 BOOL NPLAdd
  (NPLBlock** First,NPLBlock** Current,
  long Position,int Size,void* BulkData);
//
 void DeleteInstance
  (SdaiInstance Instance);
 BOOL InstanceIsValid
  (SdaiInstance Instance);
 SdaiADB BindInstance
  (CrpSDAIBaseId Instance);
 BOOL InstanceIsTerminal
  (SdaiInstance Instance);
 SdaiADB BindAggregate
  (CrpSDAIBaseId Aggregate);
 SdaiInstance CreateInstance
  (CrpSDAIRecordType RecordType,SdaiModel Model,
  SdaiInstance SubtypeInstance,
  SdaiEntity Entity,SdaiRep Repository=NULL);
//
 void DeleteRepository
  (SdaiRep Repository);
 BOOL RepositoryIsValid
  (SdaiRep Repository);
 CrpSDAIBase* DefineRepository
  (SdaiInstance Instance);
 long FindRepository
  (SdaiRep Repository);
//
 void DeletePrimitive
  (SdaiADB Primitive);
 BOOL PrimitiveIsValid
  (SdaiADB Primitive);
 BOOL GetPrimitiveValueInADBMode
  (SdaiADB block,ADBStruct* ADB);
 long LoadPrimitiveUsingSDAIRepresentation
  (long PrimitiveId,ADBStruct* ADB,
  SdaiAttr AttributeDefinition,SdaiInstance Instance);
//
 void* GetAttributeByPosition
  (SdaiInstance Instance,long Position,
  SdaiPrimitiveType ValueType,void* Value,
  SdaiAttr AttributeDefinition);
 BOOL TestAttributeByPosition
  (SdaiInstance Instance,long Position);
 void UnsetAttributeByPosition
 (SdaiInstance Instance, long Position);
//
BOOL ConvertToSDAIRepresentation
 (CrpSDAIRecordType OriginalType,CrpSDAIItem Item,
 SdaiPrimitiveType ValueType,void* Value);
//
SdaiAttr GetAttributePositionBN
 (SdaiEntity Entity,SdaiString Name,long* Position);
SdaiAttr GetAttributePosition
 (SdaiEntity Entity,SdaiAttr Attribute,long* Position);
void AddFoundAttribute
 (SdaiEntity Entity,SdaiAttr Attribute,long Position);
void PutAttribute
 (SdaiInstance Instance,SdaiAttr AttributeDefinition,
 long Position,ADBStruct* ADB);
int PutInverseAttribute
 (SdaiInstance Instance,SdaiInstance ReferedInstance,
 SdaiAttr DirectAttribute);
int      RemoveInverseAttribute
 (SdaiInstance Instance,SdaiInstance ReferedInstance,
 SdaiAttr DirectAttribute);
SdaiAttr GetInverseAttribute
 (SdaiEntity Entity,SdaiAttr DirectAttribute);
//
//
SdaiEntity GetEntityDefinition
 (SdaiSchema Schema,SdaiString EntityName);
SdaiInstance GetEntityExtent
 (SdaiModel Model,SdaiEntity Entity);
SdaiInstance GetEntityExtentBN
 (SdaiModel Model,SdaiString Name);
//
SdaiModel GetRootModel
 (long RepositoryId);
//
SdaiNPL CreateAggrAttribute
 (SdaiInstance Instance,long Position,
 SdaiAttr AttributeDefinition);
SdaiNPL CreateAggrInstance
 (CrpSDAIBase* Repository,SdaiInstance Instance,
 SdaiAttr AttributeDefinition,CrpSDAIBaseId* PrimitiveId,
 CrpSDAIBaseId BackPointer);
//
//
SdaiScope CreateEmptyScope
 (SdaiScope scopeInstance);
void DeleteScope
 (SdaiScope scopeInstance);
void FillCorrespondingTable
 (SdaiModel model,SdaiScope scope,
 SdaiAppInstance ScopeOwner,SdaiAppInstance NewScopeOwner,
 SdaiNPL CorrespondingTable);
//
void ResetReferences
 (SdaiNPL CorrespondingTable);
//
void FindInstanceUsers(SdaiAppInstance instance,SdaiNPL NPL);
//
//
 SdaiLogical ValidateScopeReferenceRestrictions
  (SdaiAppInstance ScopeOwner,SdaiScope scope,SdaiNPL Community);
 void TestExportList
  (SdaiScope scope,SdaiAppInstance TestedInstance,SdaiNPL Community);
 void TestNestedScope
  (SdaiScope scope,SdaiNPL Community);
void XORInstanceLists
 (SdaiNPL InstanceList,SdaiNPL Community);
//
//
void RefreshDB();
//
bool AddInstanceToModel
 (SdaiModel Model, SdaiInstance Instance);
bool AddInstanceToExtent
 (SdaiModel Model, SdaiInstance Instance, 
 SdaiEntity Entity, SdaiSet PopulatedFolders);
//
#pragma pack (pop)
#endif /*__FUNCT00_H*/
//
// END FUNCT00.HPP
//
