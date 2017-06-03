//
//
//
//
#ifndef __CrpSDAIBase_H
#define __CrpSDAIBase_H
#include "tfb.h"
#include "bdb.h"
#include "sdai.h"
//
#pragma pack (push, 8)
//
//
//
/*_CLASSDEF(CrpSDAIBase)*/

 class /*_CLASSTYPE*/ CrpSDAIBase
  {
private:
   BulkDataBuffer* DomainBDB;
//
   int EntityInstanceEntrySize;
   int IteratorEntrySize;
//
   int TopIteratorShift;
//
   int CrpSDAIHeaderRecordSize;
//
   int SinglePrimitiveHeaderSize;
//
   int AggregatePrimitiveEntrySize;
   int StringPrimitiveEntrySize;
   int ContinuePrimitiveEntrySize;
//
   int EntityPrimitiveEntrySize;
   int IntegerPrimitiveEntrySize;
   int BinaryPrimitiveEntrySize;
   int NumberPrimitiveEntrySize;
   int RealPrimitiveEntrySize;
   int EnumerationPrimitiveEntrySize;
   int SelectPrimitiveEntrySize;
   int BooleanPrimitiveEntrySize;
   int LogicalPrimitiveEntrySize;
   int AttributePrimitiveEntrySize;
//
//
   int ShiftOfRecordType;
   int SizeOfRecordType;
//
   int ShiftOfThirdHeaderParameter;
   int SizeOfThirdHeaderParameter;
//
   int ShiftOfBackPtr;
   int SizeOfBackPtr;
//
   int ShiftOfTopIterator;
   int SizeOfTopIterator;
//
   int ShiftOfSDAIModel;
   int SizeOfSDAIModel;
//
   int ShiftOfADBId;
   int SizeOfADBId;
//
   int ShiftOfEntityDefinitionId;
   int SizeOfEntityDefinitionId;
//
   int ShiftOfSubtypeInstanceId;
   int SizeOfSubtypeInstanceId;
//
   int ShiftOfSupertypeInstanceId;
   int SizeOfSupertypeInstanceId;
//
   int ShiftOfAttributeListId;
   int SizeOfAttributeListId;
//
   int ShiftOfNumberOfElements;
   int SizeOfNumberOfElements;
//
   int ShiftOfContinueId;
   int SizeOfContinueId;
//
   int ShiftOfAggregateContent;
//
   int ShiftOfPrimitiveContent;
//
   int SizeOfHeader;
//
//
   void* EIValidation(long Id);
public:
   FI* DomainFI;
   int SubbufferHeaderSize;
   CrpSDAIBase(FI* OriginalFI);
   CrpSDAIBase(CrpSDAIBase* OriginalBase);
   ~CrpSDAIBase();
//
   long BuildEI(CrpSDAIBaseId* SDAIModel,CrpSDAIRecordType EIType);
   long CurrentRepositoryId;
//
   long BuildEntityInstance
    (CrpSDAIBaseId CrpSDAIModel);
   long BuildSDAIInstance
    (CrpSDAIBaseId CrpSDAIModel);
//
   int SetSM
    (CrpSDAIBaseId InstanceId,long SDAIModelId);
   long CreateInstanceRoot
    (CrpSDAIRecordType InstanceType,
    CrpSDAIBaseId SDAIModel,
    CrpSDAIBaseId EntityDefinition);
//
   long BuildApplicationInstance
    (CrpSDAIBaseId CrpSDAIModel);
   long BuildDictionaryInstance
    (CrpSDAIBaseId CrpSDAIModel);
   long BuildSessionInstance
    (CrpSDAIBaseId CrpSDAIModel);
   long BuildArrayInstance
    ();
   long BuildListInstance
    ();
   long BuildSetInstance
    ();
   long BuildBagInstance
    ();
   int  DeleteEntityInstance
    (CrpSDAIBaseId InstanceId);
//
   int  SetEntityDefinition
    (CrpSDAIBaseId InstanceId,CrpSDAIBaseId EntityDefinition);
   void GetEntityDefinition
    (CrpSDAIBaseId InstanceId, CrpSDAIBaseId* Id);
   int SetSubtypeInstance
    (CrpSDAIBaseId InstanceId,CrpSDAIBaseId SubtypeInstanceId);
   void GetSubtypeInstance
    (CrpSDAIBaseId InstanceId, CrpSDAIBaseId* Id);
   int SetSupertypeInstance
    (CrpSDAIBaseId InstanceId,CrpSDAIBaseId SupertypeInstanceId);
   void GetSupertypeInstance
    (CrpSDAIBaseId InstanceId, CrpSDAIBaseId* Id);
   int SetAttributeList
    (CrpSDAIBaseId InstanceId,CrpSDAIBaseId AttributeListId);
   void GetAttributeList
    (CrpSDAIBaseId InstanceId, CrpSDAIBaseId* Id);
   void GetSDAIModel
    (CrpSDAIBaseId InstanceId, CrpSDAIBaseId* Id);
//
   long BuildPrimitiveInstance
    (CrpSDAIRecordType PrimitiveType,CrpSDAIBaseId Owner);
   int  DeletePrimitiveInstance(CrpSDAIBaseId PrimitiveInstanceId);
//
   int GetBB(long PrimitiveId,void far** BB);
//
   void GetPrimitiveId(long IteratorId, CrpSDAIBaseId* Id);
   long BuildIterator(CrpSDAIBaseId PrimitiveInstanceId,long TopIteratorId);
   int DeleteIterator(long IteratorId);
   int SetIterator(long IteratorId,long Position);
   int IncrementIterator(long IteratorId);
   int DeleteItem(long IteratorId);
   int InsertItem(long IteratorId,CrpSDAIItem Item);
   int ReplaceItem(long IteratorId,CrpSDAIItem Item);
   long GetTopIterator(long IteratorId);
   CrpSDAIRecordType GetItem(long IteratorId,CrpSDAIItem* Item);
   long GetNumberOfItems(long IteratorId);
   long GetCurrentPosition(long IteratorId);
//
   long BuildAggregatePrimitive
    (CrpSDAIRecordType PrimitiveType,
    CrpSDAIBaseId Attribute,
    CrpSDAIBaseId EntityDefinition);
//
   CrpSDAIRecordType GetRecordType(CrpSDAIBaseId RecordId);
//
int FillNewPrimitive
 (CrpSDAIRecordType PrimitiveType,
 CrpSDAIBaseId BackPointer,
 CrpSDAIItem Content,
 CrpSDAIBaseId* Primitive);
int SetSelectPrimitive
 (CrpSDAIBaseId SelectPrimitive,CrpSDAIBaseId SelectedPrimitive);
//
   SdaiNPL GetSDAIModelList();
   SdaiNPL GetSchemaInstanceList(SdaiSession Session);
   CrpSDAIRecordType GetAggregateItem
    (CrpSDAIBaseId Instance,long Position,CrpSDAIItem* Item);
   CrpSDAIRecordType GetAttributeByPosition
    (CrpSDAIBaseId Instance,long Position,CrpSDAIItem* Item);
   long GetAttributeByPosition
    (CrpSDAIBaseId Instance,long Position,CrpSDAIAttribute* Attribute);
//
   void SetADBId
    (CrpSDAIBaseId Instance,SdaiADB ADBId);
   SdaiADB GetADBId
    (CrpSDAIBaseId Instance);
//
   CrpSDAIRecordType ExtractItem
    (long PrimitiveId,CrpSDAIItem* Item);
//
   BOOL PutAttributeId
    (CrpSDAIBaseId AttributeList,
    CrpSDAIBaseId AttributeId,long Position);
   void CreateAggregateWithFixedLength
    (CrpSDAIRecordType Type,CrpSDAIBaseId BackPointer,
    long NumberOfElements, CrpSDAIBaseId* Id);
//
   long AddExtRep
    (SdaiADB ExtRep,long Position=0);
   SdaiADB GetSDAIIdForExtRep
    (long CrpId);
   long GetCrpIdForExtRep
    (SdaiADB ExtRep);
//
//

   int RefreshDB();
//
//
  };
//
#pragma pack (pop)
#endif
