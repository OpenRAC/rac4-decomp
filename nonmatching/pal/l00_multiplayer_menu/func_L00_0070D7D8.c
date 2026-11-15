/* Not matching yet: 0/12 (0.00%) relocation-masked positional words; 64/48 candidate/target bytes. All 12 target positions differ and four extra words are emitted; pointer validity is assumed. Reproduce: python tools/check_func.py --version pal func_L00_0070D7D8 nonmatching/pal/l00_multiplayer_menu/func_L00_0070D7D8.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern int D_00220ABC;
extern int D_00220AC0;
extern int D_00220AC4;

s32 func_L00_0070D7D8(void) {
    s32 node = D_00220AC0;
    s32 next;

    if (node == 0) {
        return 0;
    }

    next = *(s32 *)((u8 *)node + 0x19C);
    D_00220AC0 = next;
    if (next == 0) {
        D_00220AC4 = 0;
    }
    *(s32 *)((u8 *)node + 0x19C) = D_00220ABC;
    D_00220ABC = node;
    return node;
}
