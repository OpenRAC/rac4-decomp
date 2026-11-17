/* Not matching yet: 14/18 (77.78%) relocation-masked positional words; 72/72 candidate/target bytes. Callee return and pointer types are hypotheses. Reproduce: python tools/check_func.py --version pal func_L01_004E64A0 nonmatching/pal/l01_dreadzone_station/func_L01_004E64A0.c --diff. Not part of the build. */
/* cflags: -O1 -G8 -Wuninitialized */
#include "common.h"
extern s32 func_L01_004E62F8(void *);
extern s32 func_L01_00589E38(void *);
s32 func_L01_004E64A0(void *a) { s32 v; if (*(u8 *)(func_L01_00589E38(a)+0x10)==0) v=*(u8 *)(*(u8 **)((u8 *)a+0xAC)+0x75); else v=func_L01_004E62F8(a); return v==0; }
