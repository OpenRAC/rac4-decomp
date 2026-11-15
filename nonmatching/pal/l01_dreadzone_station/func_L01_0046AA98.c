/* Not matching yet: 12/15 (80.00%) relocation-masked positional words; 60/60 candidate/target bytes. Parameter and callee types are hypotheses. Reproduce: python tools/check_func.py --version pal func_L01_0046AA98 nonmatching/pal/l01_dreadzone_station/func_L01_0046AA98.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern s32 D_00222C20;
extern s32 func_L01_00553130(s32 *, s32, s32, s32, s32 *, s32, s32);
void func_L01_0046AA98(s32 a) { s32 v, b, c; b = a + 16; c = a + 240; v = a; func_L01_00553130(&D_00222C20, a, b, c, &v, 1, 0); }
