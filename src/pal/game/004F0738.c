/* cflags:  -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
int func_00159748(unsigned int arg0, int arg1, int arg2, unsigned int arg3, int arg4, unsigned int arg5);
int func_004F0738(_DWORD *a1, int a2, int a3, int a4)
{
  int v6;
  a1[13] = a2;
  a1[16] = a3;
  *a1 = 0;
  a1[1] = a4;
  a1[12] = 0;
  a1[14] = 0;
  a1[15] = 0;
  a1[17] = 0;
  a1[20] = 0;
  a1[22] = 0;
  a1[23] = 0;
  if (a4 == 2)
  {
    a1[19] = 24576;
  }
  else
    if (a4 == 3)
  {
    a1[19] = 1024;
  }
  else
  {
    a1[19] = 49152;
  }
  v6 = func_00159748((int) a1[19], 4096, 1024, 0, 5, (int) a1[1]);
  a1[18] = v6;
  if (v6 < 0)
    return 0;
  return 1;
}
