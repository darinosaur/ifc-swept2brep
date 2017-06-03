//
//
//
//
#ifndef __InternalStructs_H
#define __InternalStructs_H
//#include "sdaibase.hpp"
//
#pragma pack (push, 8)
// from sdaibase.hpp:
 struct CrpSDAIBaseId {long RepositoryId;long RecordId;};
//struct CrpSDAIBaseId {__int64 RepositoryId;__int64 RecordId;};
enum CrpSDAIBoolean
 {CrpSDAIBooleanFALSE,CrpSDAIBooleanTRUE};
enum CrpSDAILogical
 {CrpSDAILogicalFALSE,CrpSDAILogicalUNKNOWN,CrpSDAILogicalTRUE};
#define CrpSDAIRecordType __int16
#define CrpSDAIEntityInstance        3073
#define CrpSDAISDAIInstance          3074
#define CrpSDAIApplicationInstance   3075
#define CrpSDAIDictionaryInstance    3076
#define CrpSDAISessionInstance       3077
#define CrpSDAIArray                 3078
#define CrpSDAIList                  3079
#define CrpSDAISet                   3080
#define CrpSDAIBag                   3081
#define CrpSDAIAggregateInstance     3082
#define CrpSDAIArrayInstance         3083
#define CrpSDAIListInstance          3084
#define CrpSDAISetInstance           3085
#define CrpSDAIBagInstance           3086
#define CrpSDAIEntityInstanceId      3087
#define CrpSDAIStringValue           3088
#define CrpSDAIBinaryValue           3089
#define CrpSDAIIntegerValue          3090
#define CrpSDAINumberValue           3091
#define CrpSDAIEnumerationValue      3092
#define CrpSDAISelectValue           3093
#define CrpSDAIRealValue             3094
#define CrpSDAIBooleanValue          3095
#define CrpSDAILogicalValue          3096
#define CrpSDAIRecordContinue        3097
#define CrpSDAIIterator              3098
#define CrpSDAIAttributeValue        3099
#define CrpSDAIEmptyStringValue      3100
//
struct CrpSDAISelect    {long PrimitiveId;CrpSDAIBaseId DataType;};
struct CrpSDAIEnum      {long EnumerationName;CrpSDAIBaseId EnumerationType;};
struct CrpSDAIAttribute {long PrimitiveId;CrpSDAIBaseId AttributeDefinition;};
union  CrpSDAIItem{
 CrpSDAIBaseId      AggregateInstance;
 CrpSDAIBaseId      EntityInstance;
 char*           StringValue;
 char*          BinaryValue;
 long               IntegerValue;
 double             NumberValue;
 CrpSDAIEnum        EnumerationValue;
 CrpSDAISelect      SelectValue;
 double             RealValue;
 CrpSDAIBoolean     BooleanValue;
 CrpSDAILogical     LogicalValue;
 CrpSDAIAttribute   AttributeValue;
 };
//
//
//
//
 union PointerOrCounter {long BackPointer;
  long TopIterator;
  long SDAIModel;};
 struct CrpSDAIRecordHeader {__int16 FieldSize;CrpSDAIRecordType RecordType;
  PointerOrCounter ThirdHeaderParameter;long ADBId;};
//
 struct AggregateDataSubbufferHeader
  {CrpSDAIRecordHeader Header;long NumberOfElements;long Continue;};
//
 struct EntityPrimitiveStruct
  {CrpSDAIRecordHeader Header;long NumberOfElements;CrpSDAIBaseId Content;};
 struct IntegerPrimitiveStruct
  {CrpSDAIRecordHeader Header;long NumberOfElements;long Content;};
 struct BinaryPrimitiveStruct
  {CrpSDAIRecordHeader Header;long NumberOfElements;long Content;};
 struct NumberPrimitiveStruct
  {CrpSDAIRecordHeader Header;long NumberOfElements;double Content;};
 struct RealPrimitiveStruct
  {CrpSDAIRecordHeader Header;long NumberOfElements;double Content;};
 struct EnumerationPrimitiveStruct
  {CrpSDAIRecordHeader Header;long NumberOfElements;CrpSDAIEnum Content;};
 struct SelectPrimitiveStruct
  {CrpSDAIRecordHeader Header;long NumberOfElements;CrpSDAISelect Content;};
 struct BooleanPrimitiveStruct
  {CrpSDAIRecordHeader Header;long NumberOfElements;__int16 Content;};
 struct LogicalPrimitiveStruct
  {CrpSDAIRecordHeader Header;long NumberOfElements;__int16 Content;};
 struct AttributePrimitiveStruct
  {CrpSDAIRecordHeader Header;long NumberOfElements;CrpSDAIAttribute Content;};
//
 struct EntityInstanceStruct
  {CrpSDAIRecordHeader Header;
   CrpSDAIBaseId EntityDefinition;
   long SubtypeInstanceId;long SupertypeInstanceId;
   long AttributeListId;};
//
 struct CrpSDAIIteratorStruct
  {CrpSDAIRecordHeader Header;
   CrpSDAIBaseId PrimitiveId;
   long CurrentPosition;};
//
#pragma pack (pop)
//
#endif
