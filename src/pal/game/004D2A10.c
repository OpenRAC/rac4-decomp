/* cflags: -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
int func_0045E850(int arg0);
int func_004A2798(void * arg0, int arg1);
int func_004D2C90(void * arg0);
int func_005062D0(int arg0, int arg1);
void func_005063C0(unsigned int arg0, unsigned int arg1);
void func_004D2A10(int a1, int a2, int a3)
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
  v8 = func_004A2798((void *)(a2 + 4), 2);
  v7 = func_0045E850(v6[1]);
  func_005062D0(v8, v7);
  if ( a3 == *(_DWORD *)(a1 + 84) )
  {
    v9 = func_004A2798(v5, 2);
    func_005063C0(v9, 0x80D0D0D0);
  }
  else
  {
    v10 = func_004A2798(v5, 2);
    v11 = func_004D2C90(v6);
    func_005063C0(v10, v11);
  }
}
