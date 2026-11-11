/* cflags: -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
int D_00221A10 = 0;
__int64 func_L41_004469F8()
{
  int result; // $v0

  if ( !D_00221A10 )
    return 0;
  result = 144;
  if ( *(int *)(*(_DWORD *)(D_00221A10 + 172) + 128) < 0 )
    return 0;
  return result;
}
