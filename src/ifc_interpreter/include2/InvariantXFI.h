#pragma once
#include "sdai.h"
#include "sdaiaddt.h"
#include "sdaiaddf.h"
#include "fi.h"
#include "sdaiadb.h"
#include "adbe.h"
//
#pragma pack (push, 8)
//
#include "CommonXFI.h"
//
class XFIEXTERNAL CInvariantXFI
{
public:
	CInvariantXFI(void);
	~CInvariantXFI(void);
//
 HANDLE m_FileHandle;
 HANDLE m_ShortNamesFile;
//
// Режимы работы
//
 bool m_DeleteListOfInstances;
 bool m_StoreXFIds;
//
 CADB* m_ListOfEntityDefinitions;
 CADB* m_Separator;
 CADB* m_ListOfRecordsADB;
 CADB* m_ListOfShortNames;
//
 XFIEntityDefinition* m_LastEntityDefinition;
 XFIEntityDefinition* m_FirstEntityDefinition;
//
 SdaiRep   m_Repository;
 SdaiModel m_HeaderModel;
 SdaiModel m_CurrentSDAIModel;
//
// Обработка символов, извлеченных из файла
//
 bool m_TryToReachEOF
  (bool IgnoreRemarks = false);
 int m_GetCharacter
  (bool IgnoreRemarks);
 char* m_GetToken();
 TokenKind m_TokenKind;
 char*     m_TokenBuffer;
 void      m_InitTokenBuffer();
 int       m_TokenBufferSize;
 int       m_CurrentCharacter;
 int       m_NextCharacter;
 int       m_CurrentMeaningCharacter;
 int       m_NextMeaningCharacter;
 void      m_AddCharacterToToken(int AddedCharacter);
//
 SdaiModel m_ReadHeader(void);
 bool m_InitReading(void);
 SdaiString m_ReadSchemaNameFromFile();
//
// Функции, обеспечивающие чтение DATA SECTION
//
 SdaiModel m_ReadXF();
 SdaiModel m_ReadXF1();
 SdaiModel m_ReadXF2();
//
 bool m_LoadScopeContentFromXFPass1();
 bool m_LoadInstanceFromXFPass1(SdaiId IdInEchangeFile);
 bool m_LoadScopeContentFromXFPass2();
 bool m_LoadInstanceFromXFPass2(SdaiId IdInExchangeFile);
 bool m_LoadSimpleInstanceFromXFPass2
  (SdaiInstance Instance, XFIEntityDefinition* XFIEntity);
 bool m_SkipSimpleInstance();
 bool m_SkipAttribute();
 XFIEntityDefinition* m_AddEntityDefinition(SdaiEntity EntityDefinition);
 bool m_LoadAggr(SdaiAggr Aggregate);
 SdaiADB m_CreateSelectItem(SdaiSchema CurrentSchema, SdaiInstance DefinedType);
 SdaiInstance m_DefineReferedInstance(SdaiId IdInExchangeFile);
//
// Работа с файлом коротких имен
//
 bool m_SetFileWithShortNames(char* FileName);
 bool m_UnsetFileWithShortNames(void);
};
CInvariantXFI XFIEXTERNAL *CreateInvariantXFIForRead(char* FileName);
bool XFIEXTERNAL DeleteInvariantXFI(CInvariantXFI* InvariantXFI);
#pragma pack (pop)
