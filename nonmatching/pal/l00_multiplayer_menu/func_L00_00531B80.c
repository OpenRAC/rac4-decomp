/* Not matching yet: 13/19 (68.42%) relocation-masked positional words; 76/76 candidate/target bytes. Branch scheduling differs; the callee declaration follows the existing source. Reproduce: python tools/check_func.py --version pal func_L00_00531B80 nonmatching/pal/l00_multiplayer_menu/func_L00_00531B80.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern s32 func_004033B0(s32);
s32 func_L00_00531B80(s32 *a, s32 unused, u8 *data) {
 u8 c = *data; s32 v = func_004033B0(c); a[0]=v; if (v) {a[1]=c; return 0;} return 16;
}
