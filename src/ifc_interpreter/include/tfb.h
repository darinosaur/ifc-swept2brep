//
#ifndef __TFB_H
#define __TFB_H
#pragma pack (push, 8)
enum DataStorageOptions
 {
  Absent,
  Redefined,
  inHeaderFile,
  inDataFile,
  inExternalDataBase,
  inMemory,
  inDiscFile
 };
enum FileStatusOptions
 {
  ReadOnlyFile,
  UpdateAbleFile,
  VirtualFile,
  WorkingFile
 };
union PhysicalAddressType
 {
  void*  CommonAddress;
  long PageListShift;
  long Handler;
 };
struct PageDescription
 {
  PhysicalAddressType PhysicalAddress;
  long IntermediateAddress;
  long FileAddress;
  __int16 FileNumber;
  __int16 ThisPageHaveToBeSaved;
 };
//
#pragma pack(pop)
#endif
