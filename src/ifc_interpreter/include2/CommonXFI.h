#ifndef __COMMON_XFI
#define __COMMON_XFI
class XFIEXTERNAL XFIAttributeDefinition
{
public:
 XFIAttributeDefinition
  ();
XFIAttributeDefinition
 (SdaiEntity BaseType);
 ~XFIAttributeDefinition
  ();
//
 SdaiAttr Attribute;
 XFIAttributeDefinition* Next;
 XFIAttributeDefinition* Nested;
 SdaiPrimitiveType Type;
 SdaiInteger Lower;
 SdaiInteger Upper;
//
 SdaiPrimitiveType DefineType
  (SdaiEntity BaseType);
};
//
//
//
class XFIEXTERNAL XFIEntityDefinition
{
public:
 XFIEntityDefinition
  ();
 XFIEntityDefinition
  (SdaiEntity EntityDefinition, bool GetInherited = true);
 ~XFIEntityDefinition
  ();
 SdaiEntity Entity;
 XFIAttributeDefinition* Attribute;
 XFIEntityDefinition* Next;
 XFIEntityDefinition* NextInHeap;
 bool IsPartOfComplexEntity;
 char* Name;
 void LoadAttributes
  (bool GetInherited);
 void LoadAttributesOfComplexEntity
  ();
 void MarkRedeclaredWithExplicit
  ();
 void MarkRedeclaredWithExplicit
  (XFIAttributeDefinition* Redeclaring);
 void MarkRedeclaredWithDerived
  ();
 void MarkRedeclaredWithDerived
  (SdaiAttr Redeclaring);
};
//
 enum TokenKind
   {XFGetTokenIsUnknown,
   XFGetTokenIsEnumerationItem,
   XFGetTokenIsEOF,
   XFGetTokenIsSeparator,
   XFGetTokenIsIntegerNumber,
   XFGetTokenIsRealNumber,
   XFGetTokenIsBinary,
   XFGetTokenIsString,
   XFGetTokenIsKeyword,
   XFGetTokenIsEntityInstance,
   XFGetTokenIsEqualSign,
   XFGetTokenIsEmptyField,
   XFGetTokenIsRedefinedAttribute
   };
 //
#endif 