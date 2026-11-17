/* Not matching yet: 14/26 (53.85%) relocation-masked positional words; 104/104 candidate/target bytes. The matched callees forward eight registers; remaining call inputs are unspecified. Reproduce: python tools/check_func.py --version pal func_003FE980 nonmatching/pal/game/func_003FE980.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

/* 14/26 target words match (53.85%) under relocation-masked positional
 * comparison; 104/104 bytes. Register allocation and scheduling differ.
 * The selected PAL callees forward eight arguments, while these draft
 * declarations leave the forwarded arguments unspecified; their ABI remains
 * unresolved. Verify with tools/diff_func.py --version pal func_003FE980. */
extern s32 func_003FE9E8(s32,s32,s32,s32);
extern void func_00403308();
extern void func_00403440();
s32 func_003FE980(s32 a, s32 *b, s32 c) { s32 r; s32 *p = b; s32 q = c; r = func_003FE9E8(a,*p,q,0); if (r) {func_00403308(*p,0,q); func_00403440(*p); *p=0;} return r;}
