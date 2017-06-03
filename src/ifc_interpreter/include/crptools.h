// CRPTOOLS.HPP

#ifndef CRPTOOLS_HPP
#define CRPTOOLS_HPP
#pragma pack(push, 8)
//
//
extern "C" BOOL CRPTOOLSEXTERNAL
 AppendBuffer
 (void** Statement,long* InitialSize,int Addition);
//
extern "C" BOOL CRPTOOLSEXTERNAL
   LoseCrptoolsBuffer
 (void* LosedBuffer);
//
#pragma pack (pop)
#endif
//
// end of CRPTOOLS.HPP
