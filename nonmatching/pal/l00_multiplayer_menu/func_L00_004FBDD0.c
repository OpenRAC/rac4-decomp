/* Not matching yet: 14/18 (77.78%) relocation-masked positional words; 56/72 candidate/target bytes. Two post-return instruction pairs are omitted; their entry ownership and wrapper return ABI are unproved. Reproduce: python tools/check_func.py --version pal func_L00_004FBDD0 nonmatching/pal/l00_multiplayer_menu/func_L00_004FBDD0.c --diff. Not part of the build. */
/* cflags:  -Wuninitialized */
#include "common.h"

/* 14/18 target positions match (77.78%) under relocation-masked positional
 * comparison; 56/72 bytes. Two return-only instruction pairs after the first
 * return are omitted; their entry ownership is unresolved. The callee ABI,
 * global object extent and wrapper return use are unproved. Verify with
 * tools/diff_func.py --version pal func_L00_004FBDD0. */
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
int func_L00_00508260(void);

struct GlobalView_00498EC0 { unsigned char gap_0[84]; int field_54; };
extern struct GlobalView_00498EC0 D_00498EC0;
typedef char GlobalViewOffset_00498EC0_54[((unsigned int)&(((struct GlobalView_00498EC0 *)0)->field_54) == 84) ? 1 : -1];
typedef char GlobalViewWidth_00498EC0_54[(sizeof(((struct GlobalView_00498EC0 *)0)->field_54) == 4) ? 1 : -1];
typedef char GlobalViewPointer_00498EC0[(sizeof(void *) == 4) ? 1 : -1];
void func_L00_004FBDD0(void)
{
  int v0;

  v0 = func_L00_00508260();

  if (!D_00498EC0.field_54)
  {
    D_00498EC0.field_54 = v0 + 16;
    {
      (void) (v0 + 16);
      return;
    }
  }
  return;
}


