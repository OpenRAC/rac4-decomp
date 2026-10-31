/* cflags: @ee29 -O2 -G0 -ffast-math -Wuninitialized */
/* cflags: @ee29 -O2 -G0 -ffast-math -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
int func_001299E0(int arg0, int arg1, void * arg2, int arg3, int arg4, int arg5, int arg6);
__int64 func_00129B18(int a1, void *a2, int a3, int a4, int a5, int a6)
{
  return func_001299E0(a1, 0, a2, a3, a4, a5, a6);
}
