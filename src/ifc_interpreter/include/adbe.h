//
#ifndef __ADBE__
#define __ADBE__
//
#pragma pack(push, 1)
//
#define Tag$Empty 1
#define Tag$InternalAggr 4
#define Tag$ExternalAggr 5
#define Tag$TerminalAggr 6
#define Tag$SimpleAggr 7
#define Tag$QSBag 65
#define Tag$QIBag 66
#define Tag$RAMPtr 67
//
#define Tag$SDAIADBStruct 81
//
enum adbeStrCmpResult
{
 adbeSCR$Less,
 adbeSCR$Greater,
 adbeSCR$Equal,
 adbeSCR$Empty,
 adbeSCR$NoString
};
//
enum adbeKeyCmpResult
{
 adbeKCR$Less,
 adbeKCR$Greater,
 adbeKCR$Equal,
 adbeKCR$Empty,
 adbeKCR$NoKey
};
//
class CADB;
//
union adbeGeneralHandle
{
 __int64 FormalField;
 void*   PointerValue;
 char*   StringValue;
 SdaiId  IdValue;
 CADB*   ReferedBlock;
};
//
struct adbeSI
{
// char* KeyString;
 adbeGeneralHandle KeyString;
 SdaiId ValueId;
 SdaiId Qualifier;
};
struct adbeII
{
 SdaiId KeyId;
// SdaiId ValueId;
 adbeGeneralHandle ValueId;
 SdaiId Qualifier;
};
struct adbeIP
{
 SdaiId KeyId;
// void*  Ptr;
 adbeGeneralHandle  Ptr;
 SdaiId Qualifier;
};
struct adbeAggr
{
 adbeGeneralHandle Block;
 __int64 Counter;
 __int32 BlockSize;
 adbeGeneralHandle Definition;
};
struct adbeEmpty
{
/*
 SdaiInteger Field1;
 SdaiInteger Field2;
 SdaiInteger Field3;
*/
 __int32 Field1;
 __int32 Field2;
 __int32 Field3;
//
// Расширение для 64-разрядных указателей
//
/*
 SdaiInteger Field4;
 SdaiInteger Field5;
 SdaiInteger Field6;
 SdaiInteger Field7;
*/
//
 __int32 Field4;
 __int32 Field5;
 __int32 Field6;
 __int32 Field7;
};
struct adbeRP
{
 void* Ptr;
};
//
 union adbeADBContent
 {
  adbeSI SI;
  adbeII II;
  adbeAggr Aggr;
  adbeEmpty Empty;
  adbeRP RP;
  adbeIP IP;
  ADBStruct crpADBStruct;
 };
//
//class __declspec( dllexport ) CADB
class CRPSDAIEXTERNAL CADB
{
public:
 char Tag;
 char SubTag;
 char Storage;
 char Reserve;
 adbeADBContent Content;
 CADB
  ();
 CADB
  (char NewTag, SdaiInteger Parameter = 0);
 ~CADB();
 bool AddSIRelation
  (char* String, SdaiId Id, SdaiId Qualifier = 0);
 bool AddIIRelation
  (SdaiId Key, SdaiId Id, SdaiId Qualifier = 0);
 bool AddIPRelation
  (SdaiId Key, void* Ptr, SdaiId Qualifier = 0);
 SdaiId GetIByS
  (char* String, SdaiId Qualifier = 0);
 SdaiId GetIByI
  (SdaiId Key, SdaiId Qualifier = 0);
 void* GetPByI
  (SdaiId Key, SdaiId Qualifier = 0);
 SdaiId GetPositionByI
  (SdaiId Key, SdaiId Qualifier = 0);
 SdaiId GetMultiplePositionsByI
  (SdaiId Key, int& index);
 CADB* GetByPosition
  (SdaiInteger Position, SdaiInteger Counter = 0);
 CADB* Insert
 (SdaiInteger Position, CADB* InsertedADB, SdaiInteger Counter = 0);
 void Count
  ();
 void Clear
  ();
 void ClearContent
  ();
 CADB* Split
  ();
 adbeStrCmpResult StrCmp
  (char* String);
 adbeKeyCmpResult KeyCmp
  (SdaiId Id);
void SplitTop
 (CADB* Splited);
//
// 2012 01 09 Новые функции, эмулирующие работу класса FI
//
 bool     ReadData(__int64 Address,int size,void* Buffer);
 bool     UpdateData(__int64 Address,int size,void* Buffer);
 __int64  AddData(int size,void* Buffer,int size1=0,void* Buffer1=NULL);
 __int64  AppendCADB(int size, void* Buffer);
 __int64  CreateNestedInternalAggr(long index, int size = 0, void* Buffer = NULL);
 __int64  AppendNewItemToBlock(int size, void* Buffer);
//
// 2012 04 08 Новые функции, усовершенствующие работу механизмов
//
 __int16 QuickCount();
 __int64 InsertCADB(CADB& ADB, __int64 Position, bool MandatorySpliting = true);
};
//
// adbe related functions
//
#pragma pack(pop)
CRPSDAIEXTERNAL 
 CADB* 
 adbeCreateCADB(char NewTag, SdaiInteger Parameter = 0);
//
CRPSDAIEXTERNAL 
 void 
 adbeDeleteCADB(CADB* DeletedCADB);
#endif /*  __ADBE__  */