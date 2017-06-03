//
#ifndef __XFI
#define __XFI
//
#include "sdai.h"
#include "sdaiaddt.h"
//#include "crptools.h"
#include "sdaiaddf.h"
#include "adbe.h"
//
// 09.02.2002 PSS ListOfEntityDefinitions RAA* replaced with CADB*
//
#pragma pack (push, 8)
//
#include "CommonXFI.h"
//
//
class XFIEXTERNAL XFImage
{
public:
 bool DeleteListOfInstances;
 bool StoreXFIds;
 SdaiInstance OwnerInstance;
 SdaiRep Repository;
 XFImage
  (CStdioFile* File, XFImage* Parent = NULL, SdaiInstance Owner = 0);
 ~XFImage();
 SdaiModel ReadXF();
 SdaiModel ReadXF1();
 SdaiModel ReadXF2();
 void ReadSeparationModel(CStdioFile* File);
 long WriteXF(SdaiSchemaInstance SchemaInstance);
 void SetModel(SdaiModel Model);
 void SetRepository(SdaiRep NewRepository);
 int CurrentCharacter;
 int NextCharacter;
 XFIEntityDefinition* LastEntityDefinition;
 XFIEntityDefinition* FirstEntityDefinition;
//RAA* InvertList();
 SdaiModel ReadHeader
  ();
 CStdioFile* ShortNamesFile;
private:
 CStdioFile* XFile;
 int CurrentMeaningCharacter;
 int NextMeaningCharacter;
 char* TokenBuffer;
 int TokenBufferSize;
 SdaiModel CurrentSDAIModel;
 XFImage* ParentXFImage;
// RAA* ListOfXFImages;
// RAA* ListOfInstances;
// RAA* ListOfRecords;
 CADB* ListOfEntityDefinitions;
 CADB* Separator;
 CADB* ListOfRecordsADB;
 CADB* ListOfShortNames;
//
 TokenKind CurrentTokenKind;
//
 SdaiString ReadSchemaNameFromFile
  ();
 void InitReading
  ();
 bool TryToReachEOF
  (bool IgnoreRemarks = false);
 int GetCharacter
  (bool IgnoreRemarks);
 char* GetToken
  ();
 void AddCharacterToToken
  (int AddedCharacter);
 void InitTokenBuffer
  ();
 bool LoadScopeContentFromXFPass1
  ();
 bool LoadScopeContentFromXFPass2
  ();
 bool LoadInstanceFromXFPass1
  (SdaiId IdInEchangeFile);
 bool LoadInstanceFromXFPass2
  (SdaiId IdInEchangeFile);
 bool SkipSimpleInstance
  ();
 bool SkipAttribute
  ();
// XFIEntityDefinition* GetEntityDefinition
//  (SdaiEntity EntityDefinition);
 XFIEntityDefinition* AddEntityDefinition
  (SdaiEntity EntityDefinition);
 bool LoadSimpleInstanceFromXFPass2
  (SdaiInstance Instance, XFIEntityDefinition* XFIEntity);
 bool LoadAggr
  (SdaiAggr Aggregate);
 SdaiInstance DefineReferedInstance
  (SdaiId IdInExchangeFile);
 SdaiADB CreateSelectItem
  (SdaiSchema CurrentSchema, SdaiInstance DefinedType);
};
//
XFIEXTERNAL
XFImage* 
 CreateXFI(CStdioFile* File, XFImage* Parent = NULL, SdaiInstance Owner = 0);
XFIEXTERNAL
void DeleteXFI(XFImage* DeletedXFI);
//
#pragma pack (pop)
//
#endif
//