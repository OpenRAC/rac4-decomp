/* Not matching yet: 14/27 (51.85%) relocation-masked positional words; 108/108 candidate/target bytes. Callee interfaces, global ownership and pointer extents remain unproved. Reproduce: python tools/check_func.py --version pal func_01ECCCD8 nonmatching/pal/net/func_01ECCCD8.c --diff. Not part of the build. */
/* cflags: -mno-split-addresses -Wuninitialized */
#include "common.h"

/* 14/27 target words match (51.85%) under relocation-masked positional
 * comparison; 108/108 bytes. Register placement and scheduling differ.
 * Callee interfaces and global ownership are unproved; the loaded pointers
 * must cover the accessed +4 and +0x100 words. Verify with
 * tools/diff_func.py --version pal func_01ECCCD8. */
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
int func_01EC8EA8(int arg0, unsigned int arg1);
int func_01EC8F68(int arg0, unsigned int arg1);
int func_01ECCE40(int arg0);
extern int D_00167FB8[];
void func_01ECCCD8(int a1, unsigned int a2)
{
  int v4; // $a2
  int result; // $v0

  v4 = func_01EC8EA8(a1, a2);
  if ( v4 || (result = func_01EC8F68(a1, a2), (v4 = result) != 0) )
  {
    *(_DWORD *)(v4 + 4) = *(_DWORD *)(D_00167FB8[0] + 256);
    { (void)(func_01ECCE40(v4)); return; }
  }
  return;
}

