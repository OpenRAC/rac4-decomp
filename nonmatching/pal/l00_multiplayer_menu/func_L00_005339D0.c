/* Not matching yet: 8/13 (61.54%) relocation-masked positional words; 52/52 candidate/target bytes. Branch-likely scheduling differs; source must be terminated. Reproduce: python tools/check_func.py --version pal func_L00_005339D0 nonmatching/pal/l00_multiplayer_menu/func_L00_005339D0.c --diff. Not part of the build. */
/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"
s32 func_L00_005339D0(s8 *s) { s8 *start = s; if (*s) { ++s; while (*s) ++s; } return s-start; }
