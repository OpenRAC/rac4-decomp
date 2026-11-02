/* cflags: -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
int func_0045E038(int arg0);
int func_004A1A60(void * arg0, int arg1);
int func_004D1D80(void * arg0);
int func_00505238(int arg0, int arg1);
void func_00505328(unsigned int arg0, unsigned int arg1);
void func_004D1B00(int a1, int a2, int a3)
{
  void *v5; // $s3
  int *v6; // $s4
  int v7; // $v0
  int v8; // $s0
  unsigned int v9; // $v0
  unsigned int v10; // $s0
  unsigned int v11; // $v0

  v5 = (void *)(a2 + 4);
  v6 = *(int **)(a2 + 8);
  v8 = func_004A1A60((void *)(a2 + 4), 2);
  v7 = func_0045E038(v6[1]);
  func_00505238(v8, v7);
  if ( a3 == *(_DWORD *)(a1 + 84) )
  {
    v9 = func_004A1A60(v5, 2);
    func_00505328(v9, 0x80D0D0D0);
  }
  else
  {
    v10 = func_004A1A60(v5, 2);
    v11 = func_004D1D80(v6);
    func_00505328(v10, v11);
  }
}
