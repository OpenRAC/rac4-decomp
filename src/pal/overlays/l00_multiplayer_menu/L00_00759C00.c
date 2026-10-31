/* cflags: -G8 -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
__int64 func_0047FEB0(__int64 arg0, __int64 arg1, __int64 arg2, unsigned __int64 arg3, unsigned __int64 arg4);
extern int D_001719D0[];
extern u32 D_0021DF08;
int D_0022168C = 0;
int func_L00_00759C00(int a1)
{
  int result; // $v0

  result = 3;
  if ( D_001719D0[0] == 2 )
  {
    func_0047FEB0(16, 1, 3, 0, 0);
    D_0021DF08 = 6;
    (*(void (**)(__int64))(*(_DWORD *)(a1 + 88) + 320))(a1);
    result = 3;
  }
  D_0022168C = result;
  return result;
}
