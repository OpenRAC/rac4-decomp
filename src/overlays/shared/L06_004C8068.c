/* cflags:  -Wuninitialized -Wa,-G0 */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
extern u8 D_003A4F48[];
void func_L06_004C8068(int a1)
{
  int v1; // $a2
  __int64 result; // $v0

  v1 = *(_DWORD *)(a1 + 172);
  result = (int)&D_003A4F48 + 12 * *(__int16 *)(v1 + 248);
  *(float *)(a1 + 112) = (float)(*(float *)(*(_DWORD *)(a1 + 36) + 36)
                               * *((float *)&D_003A4F48 + 3 * *(__int16 *)(v1 + 248)))
                       * 0.66000003f;
  return;
}
