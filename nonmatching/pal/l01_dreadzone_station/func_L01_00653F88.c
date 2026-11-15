/* Not matching yet: 15/19 (78.95%) relocation-masked positional words; 76/76 candidate/target bytes. Integer-array global declaration conflicts with existing pointer-array declarations; return ABI is unproved. Reproduce: python tools/check_func.py --version pal func_L01_00653F88 nonmatching/pal/l01_dreadzone_station/func_L01_00653F88.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
extern int D_003660F8[];
__int64 func_L01_00653F88(int a1)
{
  int v1; // $a0
  int v2; // $v1
  int v3; // $a0
  int v4; // $a0

  v1 = D_003660F8[a1];
  v2 = 0;
  if ( v1 )
  {
    v3 = *(int *)(v1 + 12020);
    if ( v3 )
    {
      v4 = *(int *)(v3 + 688);
      if ( v4 )
        return *(__int16 *)(v4 + 188) == 0x20AE;
    }
  }
  return v2;
}
