/* Not matching yet: 13/20 (65.00%) relocation-masked positional words; 80/80 candidate/target bytes. Indirect callback and return ABI remain unproved. Reproduce: python tools/check_func.py --version pal func_L00_00773D98 nonmatching/pal/l00_multiplayer_menu/func_L00_00773D98.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern void *D_002234A4;
void func_L00_00773D98(u8 *arg) { u8 *v = *(u8 **)((u8 *)D_002234A4 + 0x48); if (*(void (**)(void))(v + 0x424)) (*(void (**)(void))(v + 0x424))(); if (arg[0x8c] != 0) v[0] = 0; }
