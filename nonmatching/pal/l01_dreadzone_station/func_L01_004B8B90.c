/* Not matching yet: 23/26 (88.46%) relocation-masked positional words; 104/104 candidate/target bytes. Callee return declaration conflicts with existing PAL callers and remains unproved. Reproduce: python tools/check_func.py --version pal func_L01_004B8B90 nonmatching/pal/l01_dreadzone_station/func_L01_004B8B90.c --diff. Not part of the build. */
/* cflags:  -Wuninitialized */
#include "common.h"

/* 23/26 target words match (88.46%) under relocation-masked positional
 * comparison; 104/104 bytes. Floating-point register choices differ.
 * Callee argument types follow existing PAL callers; its draft integer return
 * conflicts with their void declarations. Input and output bounds are unproved.
 * Verify with tools/diff_func.py --version pal func_L01_004B8B90. */
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
int func_0046D258(void *arg0, s32 arg1, f32 *arg2);
int func_L01_004B8B90(int a1)
{
  int v1; // $s0
  int v2; // $s1
  int result; // $v0
  float v4; // $f0
  float v5[4]; // [sp+0h] [-10h] BYREF

  v1 = a1;
  v2 = *(_DWORD *)(a1 + 172);
  result = *(unsigned __int8 *)(v2 + 1549);
  if ( *(_BYTE *)(v2 + 1549) )
  {
    result = func_0046D258((void *)a1, 0, v5);
    v4 = v5[2] - *(float *)(v1 + 24);
  }
  else
  {
    v4 = *(float *)(v2 + 1532) * 0.5f;
  }
  *(float *)(v2 + 660) = v4;
  return result;
}

