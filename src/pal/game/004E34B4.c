/* cflags: -fno-delayed-branch -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;

__int64 func_004E34B4(__int64 a1, __int64 a2, int *a3, int a4)
{
  int result; // $v0

  result = *a3;
  *(_DWORD *)(a4 + 24) = result;
  return result;
}
