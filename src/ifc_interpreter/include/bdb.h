//
//
//
//
#ifndef __BulkDataBuffer_H
#define __BulkDataBuffer_H
//
#include "tfb.h"
#include "intstr.h"
//
#pragma pack (push, 8)
//
/*_CLASSDEF(BulkDataBuffer)*/
 class /*_CLASSTYPE*/ BulkDataBuffer
  {
private:
   int BufferSize;
//   int TotalBufferSize;
   int ContinueRecordSize;
   long TotalBufferSize;
   void* Buffer;
//   int TemporaryBufferSize;
   long TemporaryBufferSize;
   void* TemporaryBuffer;
   int SubbufferHeaderSize;
   FI* DomainFI;
public:
   BulkDataBuffer(FI* InitialFI);
   ~BulkDataBuffer();
   void SetSubbufferHeaderSize(int InitialValue);
//
   int Insert(int ItemSize,int ItemPosition,void far* Item);
   int Replace(int ItemSize,int ItemPosition,void far* Item);
   int Delete(int ItemSize,int ItemPosition);
   int GetItem(int ItemSize,int ItemPosition,long* Item);
   int Get(int ItemSize,int ItemPosition,void far* Item);
   int Overwrite(int ItemSize,void far* Item);
   int Save(long PrimitiveId);
   int Load(long PrimitiveId,AggregateDataSubbufferHeader* SubbufferHeader);
   int Fill(int Size,void far* Item);
   int GetBB(void far** BB);
   int BulkDataBuffer::Request
    (int RequestedSize);
//
  };
//
#pragma pack (pop)
#endif
