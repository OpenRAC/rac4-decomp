/* cflags: -O1 -G8 -fschedule-insns -fschedule-insns2 */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef s32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
int func_0056FBC0(int arg0);
extern u8 D_003AAED8[];
int func_L01_004BDA50(int a1)
{
  int v1; // $s0
  int v2; // $s1
  int i; // $v0
  int *entry;
  int off;
  int *base = (int *)D_003AAED8;
  bool v4; // dc
  int result; // $v0

  v1 = (s32)(0);
  v2 = *(_DWORD *)(a1 + 172);
  for (;;)
  {
    off = v1 * 4;
    i = *(_DWORD *)(v2 + 896);
    entry = (int *)((off + i * 24) + (unsigned int)base);
    if (*entry == -1)
    {
      v1 = (int)v1 + 1;
    }
    else
    {
      v4 = func_0056FBC0(*(__int16 *)entry) != 0;
      result = 1;
      if ( v4 )
        return result;
      v1 = (int)v1 + 1;
    }
    if ( v1 >= 3 )
      break;
  }
  return 0;
}
