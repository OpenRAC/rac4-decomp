/* Not matching yet: 11/21 (52.38%) relocation-masked positional words; 84/84 candidate/target bytes. Global ownership, output alignment, counter lower bound and argument/return types remain unproved. Reproduce: python tools/check_func.py --version pal func_L01_005767F8 nonmatching/pal/l01_dreadzone_station/func_L01_005767F8.c --diff. Not part of the build. */
/* cflags: -mno-split-addresses -Wuninitialized */
#include "common.h"

/* 11/21 target words match (52.38%) under relocation-masked positional
 * comparison; 84/84 bytes. Register placement and scheduling differ.
 * Global ownership, output alignment, counter lower bound and argument/return
 * types remain unproved. Verify with
 * tools/diff_func.py --version pal func_L01_005767F8. */
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
extern int D_00222D40;
extern u8 D_00267220[];
__int64 func_L01_005767F8(int a1, int a2, char a3)
{
  int v3; // $a3
  char *v5; // $v1

  v3 = D_00222D40;
  if ( D_00222D40 >= 32L )
    return 0;
  ++D_00222D40;
  v5 = (char *)&D_00267220 + 12 * v3;
  v5[8] = a3;
  *(_DWORD *)v5 = a1;
  *((_DWORD *)v5 + 1) = a2;
  return 1;
}

