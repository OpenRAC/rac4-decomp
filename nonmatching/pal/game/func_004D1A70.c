/* Not matching yet: 12/17 (70.59%) relocation-masked positional words; 68/68 candidate/target bytes. Table extent and overlapping byte views remain unproved. Reproduce: python tools/check_func.py --version pal func_004D1A70 nonmatching/pal/game/func_004D1A70.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
struct arg { u32 index; u8 flag; };
extern u8 D_0021DEB8[];
int func_004D1A70(struct arg *a) { if (a->flag) return -2143272896; if (D_0021DEB8[a->index]) return -2139033360; return -2139062144; }
