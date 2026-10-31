/* cflags: -fno-delayed-branch -Wuninitialized */
/* cflags: -fno-delayed-branch -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;

float func_L41_00441FB0(int a1)
{
  return __builtin_fabsf(**(float **)(a1 + 172));
}
