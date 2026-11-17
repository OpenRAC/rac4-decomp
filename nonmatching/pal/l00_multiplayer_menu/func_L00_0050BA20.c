/* Not matching yet: 8/13 (61.54%) relocation-masked positional words; 52/52 candidate/target bytes. Branch-likely delay slot differs; source must be terminated. Reproduce: python tools/check_func.py --version pal func_L00_0050BA20 nonmatching/pal/l00_multiplayer_menu/func_L00_0050BA20.c --diff. Not part of the build. */
/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"
s32 func_L00_0050BA20(s8 *p) { s8 *start = p; if (*p) { ++p; while (*p) ++p; } return p - start; }
