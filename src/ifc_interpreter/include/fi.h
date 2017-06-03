//
#ifndef __FI_H
#define __FI_H
#pragma pack (push, 8)
#include "tfb.h"
#define FIPageSize  262144
#define FIPageMask  262143
#define FIPageShift 18
//-- definitions
//
class TFBEXTERNAL FI
{
private:
// PageDescription PD [8192];
 PageDescription PD [65536];
 int   RingQueue;
 int   SwappingLimit;
 long  FileSize;
 __int64  CurrentSize;
 char* FileName;
 char* BufferFileName;
public:
 FI(char* OriginFileName, char* TemporaryBufferFileName = NULL);
 ~FI();
//
// long  AddData(int size,void* Buffer,int size1=0,void* Buffer1=NULL);
 __int64  AddData(int size,void* Buffer,int size1=0,void* Buffer1=NULL);
 bool  ReadData(__int64 Address,int size,void* Buffer);
 bool  UpdateData(__int64 Address,int size,void* Buffer);
 void* GetPage(__int64 Address, bool SavePage = false);
 void  SetSwapping();
// long  GetDBSize
 __int64  GetDBSize
 ();
 long GetNumberOfPages
  ();
 __int64 GetMinAddress
  (long PageIndex);
 __int64 GetAddressLimit
  (long PageIndex);
 bool RefreshFile
  ();
 void SetSwappingLimit
  (int Value);
};
//
TFBEXTERNAL
FI* CreateFI
 (char* OriginFileName, char* TemporaryBufferFileName);
TFBEXTERNAL
void DeleteFI
 (FI* FIToDelete);
//
//-- end of definitions
#pragma pack(pop)
#endif
