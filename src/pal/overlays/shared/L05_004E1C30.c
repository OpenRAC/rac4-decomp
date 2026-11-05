/* cflags:  -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
int func_L05_004E06A8(int arg0);
int func_L05_004E1C30(int a1)
{
  int result; // $v0
  int v2; // $s0

  v2 = *(_DWORD *)(a1 + 172);
  result = func_L05_004E06A8(a1);
  *(_WORD *)(v2 + 334) = 0;
  return result;
}

