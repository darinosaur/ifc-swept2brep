//
// SDAIADB.HPP
//
//
#ifndef __SDAIADB_H
#define __SDAIADB_H
//
#include "sdai.h"
#include "sdaibase.h"
#include "sdaiaddt.h"
//
#pragma pack (push, 8)
#define FoundAttributesDelta 32
#define MaximumNumberOfFoundAttributes 4093
//
 enum NPLOperationResult
  {ItIsImpossible,GoToFirstBlock,GoToNextBlock,BlockFull,OK};
 enum NPLTypes
  {
//
//
//
   sdaiADBSTRUCT=1024,
   sdaiDELETEDADBSTRUCT=1025,
   sdaiNPLSTRUCT=1026,
   sdaiDELETEDNPLSTRUCT=1027,
   sdaiITERATORSTRUCT=1028,
   sdaiDELETEDITERATORSTRUCT=1029,
   sdaiINSTANCESTRUCT=1030,
   sdaiDELETEDINSTANCESTRUCT=1031,
   sdaiREPOSITORYSTRUCT=1032,
   sdaiDELETEDREPOSITORYSTRUCT=1033,
   sdaiPRIMITIVESTRUCT=1034,
   sdaiDELETEDPRIMITIVESTRUCT=1035
  };
//
//
   /*_CLASSDEF(NPLBlock)*/
   class /*_CLASSTYPE*/ NPLBlock
    {
   private:
     int Delta;
//     unsigned int BlockSizeLimit;
//     unsigned int BlockSize;
     long BlockSizeLimit;
     long BlockSize;
   public:
     NPLBlock(unsigned int Size=256,SdaiPrimitiveType=sdaiADB);
     ~NPLBlock();
     long BlockNumber;
     SdaiInstance Instance;
     SdaiAttr Attribute;
     SdaiIterator VeryFirstIterator;
     SdaiIterator VeryLastIterator;
     NPLTypes NPLType;
     void* Buffer;
     NPLBlock* Next;
     long TotalSize;
     long InitialDataSize;
     long StartPosition;
//     unsigned int UsedBlockSize;
     long UsedBlockSize;
     CrpSDAIBaseId Primitive;
//
     NPLBlock* InsertBlock
      (long Position);
     NPLOperationResult InsertData
      (long Position,int Size,void* BulkData=NULL);
     NPLOperationResult GetData
      (long Position,int Size,void* BulkData);
     NPLOperationResult PutData
      (long Position,int Size,void* BulkData);
     void SetDelta
      (int NewDelta);
     void SetLimit
      (int NewLimit);
     BOOL PutInitialData
      (SdaiPrimitiveType DataType,...);
     void MoveIteratorsLeft
      (long Position);
     void MoveIteratorsRight
      (long Position);
    };
//
//
 struct NPLStruct{NPLBlock* FirstBlock;NPLBlock* CurrentBlock;};
 struct DeletedNPLStruct{NPLBlock* FirstBlock;SdaiNPL NextDeleted;};
 struct DeletedADBStruct{SdaiADB NextDeleted;};
 struct IteratorStruct{SdaiNPL NPL;long Position;};
 struct DeletedIteratorStruct{SdaiIterator NextDeleted;};
 struct DeletedInstanceStruct{SdaiInstance NextDeleted;};
 struct RepositoryStruct{long Id;CrpSDAIBase* Repository;};
// struct DeletedRepositoryStruct{long Id;SdaiRep NextDeleted};
 struct DeletedRepositoryStruct{SdaiRep NextDeleted;};
 struct DeletedPrimitiveStruct{SdaiADB NextDeleted;};
 struct SelectStruct{SdaiInstance DataType;SdaiADB Value;};
//
 union ADBContent
  {
   SdaiInteger             IntegerValue     ;
   SdaiReal                RealValue        ;
   SdaiBoolean             BooleanValue     ;
   SdaiLogical             LogicalValue     ;
   SdaiString              StringValue      ;
   SdaiBinary              BinaryValue      ;
   SdaiEnum                EnumValue        ;
   SdaiInstance            InstanceValue    ;
   SdaiAggr                AggrValue        ;
   SdaiString              ConstantString   ;
   NPLStruct               NPL              ;
   DeletedNPLStruct        DeletedNPL       ;
   DeletedADBStruct        DeletedADB       ;
   IteratorStruct          Iterator         ;
   DeletedIteratorStruct   DeletedIterator  ;
   CrpSDAIBaseId           Instance         ;
   DeletedInstanceStruct   DeletedInstance  ;
   RepositoryStruct        Repository       ;
   DeletedRepositoryStruct DeletedRepository;
   CrpSDAIBaseId           Primitive        ;
   DeletedPrimitiveStruct  DeletedPrimitive ;
   SelectStruct            SelectValue;
  };
//
 struct ADBStruct
  {SdaiPrimitiveType Type;ADBContent Content;};
//
//
struct EntityWithInverseAttributeStruct
 {SdaiEntity Entity;long NumberOfInverseAttributes;};
struct InverseAttributeStruct
 {SdaiAttr InverseAttribute;SdaiAttr InvertedAttribute;};
union InverseAttributeDescription
 {EntityWithInverseAttributeStruct Entity;
 InverseAttributeStruct Attribute;};
//
//
//
//
#pragma pack (pop)
#endif
//
// END SDAIADB.HPP
//
