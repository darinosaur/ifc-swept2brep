/*************************************************************************/
/* This header file <sdai.h> is related to ISO CD 10303-24               */
/*************************************************************************/
//
// 2011 09 29 Peter Shilnikov: all long typedefs are replaced with __int64
//
#ifndef _SDAI_
#define _SDAI_
#pragma pack (push, 8)

/*** Constant declarations ***********************************************/

/* LOGICAL and BOOLEAN value elements: */

#define sdaiFALSE   0
#define sdaiTRUE    1
#define sdaiUNKNOWN 2

/* BINARY value elements: */

#define sdaiBIT0 '0'
#define sdaiBIT1 '1'

/* EXPRESS built-in constants: */

#define sdaiE  2.7182818284590451353602874713
#define sdaiPI 3.1415926353897932384626433832

/* SDAI C late binding error codes: *************************/

#define sdaiNO_ERR   0   /* No error                        */
#define sdaiSS_OPN  10   /* Session open                    */
#define sdaiSS_NAVL  20   /* SDAI not available             */
#define sdaiSS_NOPN  30   /* Session is not open            */
#define sdaiRP_NEXS  40   /* Repository does not exist      */
#define sdaiRP_NAVL  50   /* Repository not available       */
#define sdaiRP_OPN  60   /* Repository open                 */
#define sdaiRP_NOPN  70   /* Repository is not open         */
#define sdaiTR_EAB  75   /* Transaction ended abnormally    */
#define sdaiTR_EXS  80   /* Transaction exists              */
#define sdaiTR_NAVL  85   /* Transaction not available      */
#define sdaiTR_NRO  90   /* Transaction not read-only       */
#define sdaiTR_NRW 100   /* Transaction not read-write      */
#define sdaiTR_NEXS 110   /* Transaction does not exist     */
#define sdaiSD_NDEF 120   /* Schema definition is not defined*/
#define sdaiMO_NEXS 130   /* SDAI-model does not exist      */
#define sdaiMO_NAVL 140   /* SDAI-model is not active       */
#define sdaiMX_NVLD 150   /* SDAI-model access invalid      */
#define sdaiMX_NRO 160   /* SDAI-model access not read-only */
#define sdaiMX_NRW 170   /* SDAI-model access not read-write*/
#define sdaiMX_NDEF 180   /* SDAI-model access not defined  */
#define sdaiMX_RW 185   /* SDAI-model access read-write     */
#define sdaiMO_NVLD 190   /* SDAI-model invalid             */
#define sdaiMO_DUP 200   /* SDAI-model duplicate            */
#define sdaiED_NDEF 210   /* Entity definition not defined  */
#define sdaiTY_NDEF 220   /* Type not defined               */
#define sdaiTY_NVLD 230   /* Type invalid                   */
#define sdaiRU_NEXS 240   /* Rule does not exist            */
#define sdaiFN_NAVL 250   /* Function not available         */
#define sdaiEI_NEXS 260   /* Entity instance does not exist */
#define sdaiAT_NDEF 270   /* Attribute not defined          */
#define sdaiSI_DUP 280   /* Schema instance duplicate       */
#define sdaiVT_NVLD 290   /* Value type invalid             */
#define sdaiAG_NEXS 300   /* Aggregate does not exist       */
#define sdaiIR_NEXS 310   /* Iterator does not exist        */
#define sdaiAG_NSET 320   /* Aggregate is empty             */
#define sdaiIR_NSET 330   /* Current member is not defined  */
#define sdaiAD_NVLD 340   /* Aggregate definition invalid   */
#define sdaiVA_NSET 350   /* Value not set                  */
#define sdaiIX_NVLD 360   /* Index invalid                  */
#define sdaiED_NAVL 370   /* Entity definition is not available*/
#define sdaiSI_NEXS 380   /* Schema instance does not exist */
#define sdaiEI_NAVL 390   /* Entity instance not available  */
#define sdaiSC_DUP 400   /* Scope duplicate                 */
#define sdaiEI_NEXP 410   /* Entity instance not exported   */
#define sdaiMO_NDEQ 420   /* SDAI-model not domain equivalent*/
#define sdaiSD_NVLD 430   /* Schema definition invalid      */
#define sdaiSY_ERR1000   /* Underlying system error         */

/*** Type declarations **************************************/

typedef unsigned char    SdaiBit;

/* C late binding primitive data types: */

// typedef long             SdaiInteger;   //??????
typedef __int64             SdaiInteger;   //??????
typedef double           SdaiReal;
//typedef int              SdaiBoolean;
//typedef __int16              SdaiBoolean;
typedef short              SdaiBoolean;
//typedef int              SdaiLogical;
//typedef __int16              SdaiLogical;
typedef short              SdaiLogical;
typedef char             *SdaiString;
//typedef SdaiBit          *SdaiBinary;
typedef char             *SdaiBinary;

/* enumeration data type:                */

typedef char             *SdaiEnum;

/* aggregate data types:                 */
// typedef long              SdaiAggrId;
typedef __int64              SdaiAggrId;
typedef SdaiAggrId        SdaiAggr;
typedef SdaiAggr          SdaiOrderedAggr;
typedef SdaiAggr          SdaiUnorderedAggr;
typedef SdaiOrderedAggr   SdaiArray;
typedef SdaiOrderedAggr   SdaiList;
typedef SdaiUnorderedAggr SdaiSet;
typedef SdaiUnorderedAggr SdaiBag;

/* entity instance identifier type:       */

//typedef long              SdaiId;         //???????
typedef __int64              SdaiId;         //???????
typedef SdaiId            SdaiInstance;

/* SDAI instance identifier types:        */

typedef SdaiInstance      SdaiAppInstance;
typedef SdaiInstance      SdaiModel;
typedef SdaiInstance      SdaiRep;
typedef SdaiInstance      SdaiSession;
typedef SdaiInstance      SdaiAttr;
typedef SdaiAttr          SdaiExplicitAttr;
typedef SdaiInstance      SdaiEntity;
typedef SdaiInstance      SdaiWhereRule;
typedef SdaiInstance      SdaiUniRule;
typedef SdaiInstance      SdaiGlobalRule;
typedef SdaiInstance      SdaiSchema;
typedef SdaiInstance      SdaiScope;
typedef SdaiInstance      SdaiSchemaInstance;
typedef SdaiInstance      SdaiTrx;

/* SDAI iterator identifier type:          */

//typedef long              SdaiItrId ;//???????????
typedef __int64              SdaiItrId ;//???????????
typedef SdaiItrId         SdaiIterator;

/* Non-persistent list data type:          */

typedef SdaiList          SdaiNPL;

/* access mode data type:                   */

typedef enum {sdaiRO, sdaiRW} SdaiAccessMode;

/* C late binding ADB identifier type:      */

//typedef long              SdaiADBId;    //??????????
typedef __int64              SdaiADBId;    //??????????
typedef SdaiADBId         SdaiADB;

/* attribute type data type:                */

typedef enum {
                         sdaiADB, sdaiAGGR, sdaiBINARY, sdaiBOOLEAN,
                         sdaiENUM, sdaiINSTANCE, sdaiINTEGER,
                         sdaiLOGICAL, sdaiNOTYPE, sdaiREAL, sdaiSTRING
       } SdaiPrimitiveType;

/* aggregate index data type:                 */

typedef long              SdaiIndexId;//?????????????
typedef SdaiIndexId       SdaiAggrIndex;

/* error code data type:                       */

typedef long              SdaiErrorId  ;//????????????
typedef SdaiErrorId       SdaiErrorCode;

/* error handler data type:                    */

typedef void     (*SdaiErrorHandler)(SdaiErrorCode);

/* transaction commit mode data type:           */

typedef enum {sdaiABORT, sdaiCOMMIT} SdaiCommitMode;

//
//
//
//
/*** The ANSI-C style prototype functions of the SDAI
     operations. **********************************************/

CRPSDAIEXTERNAL
int              sdaiLogicalCompare           (SdaiLogical         value1,
                                               SdaiLogical         value2);
CRPSDAIEXTERNAL
SdaiErrorCode    sdaiErrorQuery               (void);
CRPSDAIEXTERNAL
void             sdaiSetErrorHandler          (SdaiErrorHandler    function);
CRPSDAIEXTERNAL
SdaiErrorHandler sdaiRestoreErrorHandler      (void);
CRPSDAIEXTERNAL
void             sdaiRecordEvent              (SdaiSession         session,
                       SdaiString          functionName,
                       SdaiErrorCode       error,
                       SdaiString          description);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiSetEventRecording        (SdaiSession         session,
                 SdaiBoolean         setRec);
CRPSDAIEXTERNAL
SdaiSession      sdaiOpenSession              (void);
CRPSDAIEXTERNAL
void             sdaiCloseSession             (SdaiSession         session);
CRPSDAIEXTERNAL
SdaiRep          sdaiOpenRepository           (SdaiSession         session,
                                               SdaiRep             repository);
CRPSDAIEXTERNAL
SdaiRep          sdaiOpenRepositoryBN         (SdaiSession         session,
                       SdaiString          repositoryName);
CRPSDAIEXTERNAL
void             sdaiCloseRepository          (SdaiRep             repository);
CRPSDAIEXTERNAL
SdaiTrx          sdaiStartTrx                 (SdaiSession         session,
                                               SdaiAccessMode      mode);
CRPSDAIEXTERNAL
void             sdaiBreakTrx                 (SdaiTrx             transaction,
                                               SdaiCommitMode      mode);
CRPSDAIEXTERNAL
void             sdaiEndTrx                   (SdaiTrx             transaction,
                                               SdaiCommitMode      mode);
CRPSDAIEXTERNAL
SdaiNPL          sdaiCreateNPL                (void);
CRPSDAIEXTERNAL
void             sdaiDeleteNPL                (SdaiNPL             list);
CRPSDAIEXTERNAL
SdaiInteger      sdaiQuery                    (SdaiAggr            source,
                 SdaiString          criteria,
                 SdaiInstance        instance,
                 SdaiNPL             result);
CRPSDAIEXTERNAL
SdaiLogical      sdaiIsRecordingOn            (SdaiSession         session);
CRPSDAIEXTERNAL
SdaiADB          sdaiCreateADB                (SdaiPrimitiveType   valueType, ...);
CRPSDAIEXTERNAL
SdaiADB          sdaiCreateEmptyADB           (void);
CRPSDAIEXTERNAL
void             *sdaiGetADBValue             (SdaiADB             block,
                 SdaiPrimitiveType   valueType,
                 void               *value);
CRPSDAIEXTERNAL
void             sdaiPutADBValue              (SdaiADB             block,
                                               SdaiPrimitiveType   valueType, ...);
CRPSDAIEXTERNAL
SdaiPrimitiveType sdaiGetADBType              (SdaiADB             block);
CRPSDAIEXTERNAL
void              sdaiDeleteADB               (SdaiADB             block);
CRPSDAIEXTERNAL
SdaiSchemaInstance sdaiCreateSchemaInstance   (SdaiString          schemaInstanceName,
                 SdaiSchema          schema,
                 SdaiRep             repository);
CRPSDAIEXTERNAL
SdaiSchemaInstance sdaiCreateSchemaInstanceBN (SdaiString          schemaInstanceName,
                 SdaiString          schemaName,
                 SdaiRep             repository);
CRPSDAIEXTERNAL
void             sdaiDeleteSchemaInstance     (SdaiSchemaInstance  schemaInstance);
CRPSDAIEXTERNAL
void             sdaiAddModel                 (SdaiSchemaInstance  schemaInstance,
                                               SdaiModel           model);
CRPSDAIEXTERNAL
void             sdaiRemoveModel              (SdaiSchemaInstance  schemaInstance,
                                               SdaiModel           model);
CRPSDAIEXTERNAL
SdaiModel        sdaiCreateModel              (SdaiRep             repository,
                                               SdaiString          modelName,
                                               SdaiSchema          schema);
CRPSDAIEXTERNAL
SdaiModel        sdaiCreateModelBN            (SdaiRep             repository,
                                               SdaiString          modelName,
                       SdaiString          schemaName);
CRPSDAIEXTERNAL
void             sdaiDeleteModel              (SdaiModel           model);
CRPSDAIEXTERNAL
void             sdaiRenameModel              (SdaiModel           model,
                                               SdaiString          modelName);
CRPSDAIEXTERNAL
SdaiModel        sdaiAccessModel              (SdaiModel           model,
                                               SdaiAccessMode      mode);
CRPSDAIEXTERNAL
SdaiModel        sdaiAccessModelBN            (SdaiRep             repository,
                                               SdaiString          modelName,
                                               SdaiAccessMode      mode);
CRPSDAIEXTERNAL
void             sdaiPromoteModel             (SdaiModel           model);
CRPSDAIEXTERNAL
void             sdaiEndModelAccess           (SdaiModel           model);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateGlobalRule       (SdaiSchemaInstance  schemaInstance,
                 SdaiGlobalRule      rule,
                 SdaiNPL            *list);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateGlobalRuleBN     (SdaiSchemaInstance  schemaInstance,
                 SdaiString          ruleName,
                 SdaiNPL            *list);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateUniqueness       (SdaiSchemaInstance  schemaInstance,
                 SdaiUniRule         uniRule,
                 SdaiInstance       *instance);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateUniquenessBN     (SdaiSchemaInstance  schemaInstance,
                 SdaiString          entityName,
                 SdaiString          uniRuleName,
                 SdaiInstance       *instance);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateReferenceDomain  (SdaiSchemaInstance schemaInstance,
                                               SdaiAppInstance    appInstance,
                                               SdaiNPL            *list);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateSchemaInstance   (SdaiSchemaInstance schemaInstance);
CRPSDAIEXTERNAL
SdaiLogical      sdaiIsValidationCurrent      (SdaiSchemaInstance schemaInstance);
CRPSDAIEXTERNAL
SdaiSchema       sdaiGetSchema                (SdaiString         schemaName);
CRPSDAIEXTERNAL
SdaiSchemaInstance sdaiGetSchemaInstance      (SdaiString         schemaInstanceName,
                                               SdaiRep            repository);
CRPSDAIEXTERNAL
SdaiEntity       sdaiGetEntity                (SdaiModel          model,
                                               SdaiString         name);
CRPSDAIEXTERNAL
SdaiAppInstance  sdaiCreateInstance           (SdaiModel          model,
                                               SdaiEntity         entity);
CRPSDAIEXTERNAL
SdaiAppInstance  sdaiCreateInstanceBN         (SdaiModel          model,
                                               SdaiString         entityName);
CRPSDAIEXTERNAL
void             sdaiUndoChanges              (SdaiModel          model);
CRPSDAIEXTERNAL
void             sdaiSaveChanges              (SdaiModel          model);
CRPSDAIEXTERNAL
SdaiAppInstance  sdaiCreateComplexInstance    (SdaiModel          model,
                                               SdaiNPL            entityList);
CRPSDAIEXTERNAL
SdaiAppInstance  sdaiCreateComplexInstanceBN  (SdaiModel          model,
                                               SdaiNPL            nameList);
CRPSDAIEXTERNAL
SdaiSet          sdaiGetEntityExtent          (SdaiModel          model,
                                               SdaiEntity         entity);
CRPSDAIEXTERNAL
SdaiSet          sdaiGetEntityExtentBN        (SdaiModel          model,
                                               SdaiString         name);
CRPSDAIEXTERNAL
void             sdaiAddToScope               (SdaiAppInstance    scopeInstance,
                                               SdaiAppInstance    instance);
CRPSDAIEXTERNAL
SdaiLogical      sdaiIsScopeOwner             (SdaiAppInstance    instance);
CRPSDAIEXTERNAL
SdaiScope        sdaiGetScope                 (SdaiAppInstance    instance);
CRPSDAIEXTERNAL
void             sdaiRemoveFromScope          (SdaiScope          scope,
                                               SdaiAppInstance    instance);
CRPSDAIEXTERNAL
void             sdaiAddToExportList          (SdaiScope          scope,
                                               SdaiAppInstance    instance);
CRPSDAIEXTERNAL
void             sdaiRemoveFromExportList     (SdaiScope          scope,
                                               SdaiAppInstance    instance);
CRPSDAIEXTERNAL
void             sdaiScopedDelete             (SdaiScope          scope);
CRPSDAIEXTERNAL
SdaiScope        sdaiScopedCopyInSameModel    (SdaiScope          scope);
CRPSDAIEXTERNAL
SdaiScope        sdaiScopedCopyToOtherModel   (SdaiScope          scope,
                                               SdaiModel          model);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateScopeReferenceRestrictions (SdaiAppInstance instance);
CRPSDAIEXTERNAL
SdaiSet          sdaiGetOwnedScopeInstances   (SdaiAppInstance    appInstance);
CRPSDAIEXTERNAL
SdaiAppInstance  sdaiGetScopeOwner            (SdaiAppInstance    appInstance);
CRPSDAIEXTERNAL
SdaiSet          sdaiGetExportList            (SdaiAppInstance    appInstance);
CRPSDAIEXTERNAL
SdaiEntity       sdaiGetComplexEntity         (SdaiNPL            entityList);
CRPSDAIEXTERNAL
SdaiEntity       sdaiGetComplexEntityBN       (SdaiString         schemaName,
                                               SdaiNPL            nameList);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiIsSubtypeOf              (SdaiEntity         subtype,
                                               SdaiEntity         supertype);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiIsSubtypeOfBN            (SdaiString         schemaName,
                 SdaiString         subName,
                                               SdaiString         superName);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiIsSDAISubtypeOf          (SdaiEntity         subtype,
                                               SdaiEntity         supertype);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiIsSDAISubtypeOfBN        (SdaiString         schemaName,
                                               SdaiString         subName,
                                               SdaiString         superName);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiIsDeqWith                (SdaiEntity         entityType1,
                                               SdaiEntity         entityType2);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiIsDeqWithBN              (SdaiString         schemaName,
                                               SdaiString         entityName1,
                                               SdaiString         entityName2);
CRPSDAIEXTERNAL
SdaiAttr         sdaiGetAttrDefinition        (SdaiEntity         entity,
                                               SdaiString         attrName);
CRPSDAIEXTERNAL
SdaiAttr         sdaiGetAttrDefinitionBN      (SdaiString         schemaName,
                                               SdaiString         entityName,
                                               SdaiString         attrName);
CRPSDAIEXTERNAL
void*            sdaiGetAttr                  (SdaiInstance       instance,
                                               SdaiAttr           attribute,
                             SdaiPrimitiveType  valueType,
                             void              *value);
CRPSDAIEXTERNAL
void*            sdaiGetAttrBN                (SdaiInstance       instance,
                                               SdaiString         attributeName,
                             SdaiPrimitiveType  valueType,
                             void              *value);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiTestAttr                 (SdaiInstance       instance,
                                               SdaiAttr           attribute);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiTestAttrBN               (SdaiInstance       instance,
                                               SdaiString         attributeName);
CRPSDAIEXTERNAL
SdaiModel        sdaiGetInstanceModel         (SdaiInstance       instance);
CRPSDAIEXTERNAL
SdaiEntity       sdaiGetInstanceType          (SdaiInstance       instance);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiIsInstanceOf             (SdaiInstance       instance,
                                               SdaiEntity         entity);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiIsInstanceOfBN           (SdaiInstance       instance,
                                               SdaiString         entityName);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiIsKindOf                 (SdaiInstance       instance,
                                               SdaiEntity         entity);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiIsKindOfBN               (SdaiInstance       instance,
                                               SdaiString         entityName);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiIsSDAIKindOf             (SdaiInstance       instance,
                                               SdaiEntity         entity);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiIsSDAIKindOfBN           (SdaiInstance       instance,
                                               SdaiString         entityName);
CRPSDAIEXTERNAL
SdaiNPL          sdaiFindInstanceUsers        (SdaiInstance       instance,
                       SdaiNPL            domain,
                       SdaiNPL            resultList);
CRPSDAIEXTERNAL
void             sdaiGetAttrs                 (SdaiInstance       instance,
                                               SdaiInteger        numberAttr,
                                               SdaiAttr           attribute,
                                               SdaiPrimitiveType  valueType,
                                               void              *value, ...);
CRPSDAIEXTERNAL
void             sdaiGetAttrsBN               (SdaiInstance       instance,
                                               SdaiInteger        numberAttr,
                                               SdaiString         attributeName,
                                               SdaiPrimitiveType  valueType,
                                               void              *value, ...);
CRPSDAIEXTERNAL
SdaiADB          *sdaiGetAllAttrs             (SdaiInstance       instance,
                                               SdaiInteger       *numberAttr);
CRPSDAIEXTERNAL
SdaiAppInstance  sdaiNearCopyInstance         (SdaiAppInstance    instance);
CRPSDAIEXTERNAL
SdaiAppInstance  sdaiFarCopyInstance          (SdaiAppInstance    instance,
                                               SdaiModel          model);
CRPSDAIEXTERNAL
void             sdaiDeleteInstance           (SdaiAppInstance    instance);
CRPSDAIEXTERNAL
void             sdaiPutAttr                  (SdaiAppInstance    instance,
                                               SdaiExplicitAttr   attribute,
                                               SdaiPrimitiveType  valueType, ...);
CRPSDAIEXTERNAL
void             sdaiPutAttrBN                (SdaiAppInstance    instance,
                                               SdaiString         attributeName,
                                               SdaiPrimitiveType  valueType, ...);
CRPSDAIEXTERNAL
void             sdaiUnsetAttr                (SdaiAppInstance    instance,
                                               SdaiExplicitAttr   attribute);
CRPSDAIEXTERNAL
void             sdaiUnsetAttrBN              (SdaiAppInstance    instance,
                                               SdaiString         attributeName);
CRPSDAIEXTERNAL
SdaiAggr         sdaiCreateAggr               (SdaiAppInstance    instance,
                                               SdaiExplicitAttr   attribute);
CRPSDAIEXTERNAL
SdaiAggr         sdaiCreateAggrBN             (SdaiAppInstance    instance,
                                               SdaiString         attributeName);
CRPSDAIEXTERNAL
SdaiString       sdaiGetPersistentLabel       (SdaiAppInstance    instance,
                                               SdaiString         labelBuffer);
CRPSDAIEXTERNAL
SdaiAppInstance  sdaiGetSessionId             (SdaiRep            repository,
                                               SdaiString         label);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateWhereRule        (SdaiAppInstance    instance,
                                               SdaiWhereRule      rule);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateWhereRuleBN      (SdaiAppInstance    instance,
                                               SdaiString         ruleName);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiValidateRequiredAttrs    (SdaiAppInstance    instance,
                                               SdaiNPL           *list);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateInverseAttrs     (SdaiAppInstance    instance,
                                         SdaiNPL           *list);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateAttrTypes        (SdaiAppInstance    instance,
                                               SdaiNPL           *list);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateAggrSizes        (SdaiAppInstance    instance,
                                               SdaiNPL           *list);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateAggrUni          (SdaiAppInstance    instance,
                                               SdaiNPL           *list);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateArraySparseness  (SdaiAppInstance    instance,
                                               SdaiNPL           *list);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateStringWidth      (SdaiAppInstance    appInstance,
                                               SdaiNPL           *list);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateBinaryWidth      (SdaiAppInstance    appInstance,
                                               SdaiNPL           *list);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateRealPrecision    (SdaiAppInstance    appInstance,
                                               SdaiNPL           *list);
CRPSDAIEXTERNAL
void             sdaiPutAttrs                 (SdaiAppInstance    appInstance,
                                               SdaiInteger        numberAttr,
                                               SdaiAttr           attribute,
                                               SdaiPrimitiveType  valueType, ...);
CRPSDAIEXTERNAL
void             sdaiPutAttrsBN               (SdaiAppInstance    appInstance,
                                               SdaiInteger        numberAttr,
                                               SdaiString         attributeName,
                                               SdaiPrimitiveType  valueType, ...);
CRPSDAIEXTERNAL
void             sdaiPutAllAttrs              (SdaiAppInstance    appInstance,
                                               SdaiInteger        numberAttr,
                                               SdaiADB           *values);
CRPSDAIEXTERNAL
SdaiInteger      sdaiGetMemberCount           (SdaiAggr           aggregate);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiIsMember                 (SdaiAggr           aggregate,
                                               SdaiPrimitiveType  valueType, ...);
CRPSDAIEXTERNAL
SdaiIterator     sdaiCreateIterator           (SdaiAggr           aggregate);
CRPSDAIEXTERNAL
void             sdaiDeleteIterator           (SdaiIterator       iterator);
CRPSDAIEXTERNAL
void             sdaiBeginning                (SdaiIterator       iterator);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiNext                     (SdaiIterator       iterator);
CRPSDAIEXTERNAL
void*            sdaiGetAggrByIterator        (SdaiIterator       iterator,
                             SdaiPrimitiveType  valueType,
                                               void              *value);
CRPSDAIEXTERNAL
SdaiAggr         sdaiCreateNestedAggrByItr    (SdaiAggr           aggregate,
                                               SdaiIterator       current);
CRPSDAIEXTERNAL
void             sdaiPutAggrByIterator        (SdaiIterator       iterator,
                                               SdaiPrimitiveType  valueType, ...);
CRPSDAIEXTERNAL
void             sdaiRemove                   (SdaiIterator       iterator);
CRPSDAIEXTERNAL
void             sdaiAdd                      (SdaiUnorderedAggr  unorderedAggr,
                                               SdaiPrimitiveType  valueType, ...);
CRPSDAIEXTERNAL
SdaiAggr         sdaiCreateNestedAggr         (SdaiUnorderedAggr  aggregate);
CRPSDAIEXTERNAL
void*            sdaiGetAggrByIndex           (SdaiOrderedAggr    aggregate,
                                               SdaiAggrIndex      index,
                                               SdaiPrimitiveType  valueType,
                                               void              *value);
CRPSDAIEXTERNAL
void             sdaiEnd                      (SdaiIterator       iterator);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiPrevious                 (SdaiIterator       iterator);
CRPSDAIEXTERNAL
void             sdaiPutAggrByIndex           (SdaiOrderedAggr    aggregate,
                                               SdaiAggrIndex      index,
                                               SdaiPrimitiveType  valueType, ...);
CRPSDAIEXTERNAL
SdaiAggr         sdaiCreateNestedAggrByIndex  (SdaiOrderedAggr    aggregate,
                                               SdaiAggrIndex      index);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiTestArrayByIndex         (SdaiArray          array,
                                               SdaiAggrIndex      index);
CRPSDAIEXTERNAL
SdaiBoolean      sdaiTestArrayByItr           (SdaiIterator       iterator);
CRPSDAIEXTERNAL
void             sdaiUnsetArrayByIndex        (SdaiArray          array,
                                               SdaiAggrIndex      index);
CRPSDAIEXTERNAL
void             sdaiUnsetArrayByItr          (SdaiIterator       iterator);
CRPSDAIEXTERNAL
void             sdaiInsertBefore             (SdaiIterator       iterator,
                                               SdaiPrimitiveType  valueType, ...);
CRPSDAIEXTERNAL
void             sdaiInsertAfter              (SdaiIterator       iterator,
                                               SdaiPrimitiveType  valueType, ...);
CRPSDAIEXTERNAL
void             sdaiPrepend                  (SdaiList           list,
                                               SdaiPrimitiveType  valueType, ...);
CRPSDAIEXTERNAL
void             sdaiAppend                   (SdaiList           list,
                                               SdaiPrimitiveType  valueType, ...);
CRPSDAIEXTERNAL
void             sdaiIndexedRemove            (SdaiList           list,
                                               SdaiAggrIndex      index);
CRPSDAIEXTERNAL
SdaiList         sdaiCreateAttrTypePath       (SdaiAppInstance    instance,
                                               SdaiAttr           attribute);
CRPSDAIEXTERNAL
SdaiList         sdaiCreateAggrTypePathByIndex (SdaiOrderedAggr   aggregate,
                                                SdaiAggrIndex     index);
CRPSDAIEXTERNAL
SdaiList         sdaiCreateAggrTypePathByItr  (SdaiIterator       iterator);
CRPSDAIEXTERNAL
SdaiList         sdaiGetADBTypePath           (SdaiADB            block);
CRPSDAIEXTERNAL
SdaiLogical      sdaiValidateTypePath         (SdaiAppInstance    appInstance,
                 SdaiNPL           *list);
#pragma pack (pop)
#endif /* _SDAI_ */
