/* Not matching yet: 13/15 (86.67%) relocation-masked positional words; 52/60 candidate/target bytes. Two words after return are omitted; callback ABI is unknown. Reproduce: python tools/check_func.py --version pal func_L00_005212C8 nonmatching/pal/l00_multiplayer_menu/func_L00_005212C8.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
s32 func_L00_005212C8(s32 (**a)()) { s32 (*f)(); if ((a == 0) || ((f = *a) == 0)) return -1; return f(a); }
