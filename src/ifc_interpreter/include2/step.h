#ifndef _STEP
#define _STEP
//
#pragma pack (push, 8)
//
//
//
//
class __declspec( dllexport ) cSTEPEntity
 {
public:
  long EntityId;
  SdaiEntity Entity;
//
  long AttributeId;
  SdaiString Name;
  SdaiString ShortName;
  cSTEPEntity* Next;
  bool IsPartOfComplexEntity;
//
  cSTEPEntity
   (SdaiEntity OriginalEntity);
  ~cSTEPEntity
   ();
//
  void LoadAttributes
   (BOOL GetInherited=TRUE);
  void LoadAllAttributes
   ();
  void MarkRedeclaredWithExplicit
   (cSTEPEntity* StartEntity);
  void MarkRedeclaredWithDerived
   (SdaiNPL ListOfDerived,int NumberOfDerived);
 };
//
//
//
class __declspec( dllexport ) cSTEPAttribute
 {
public:
  long AttributeId;
  long EntityId;
//
  long Next;
  long Nested;
  long Parent;
//
  SdaiInteger Lower;
  SdaiInteger Upper;
  SdaiPrimitiveType Type;
  SdaiString Name;
  SdaiAttr Attribute;
//
  cSTEPAttribute
   ();
  ~cSTEPAttribute
   ();
 };
//
#pragma pack (pop)
//
#endif
