/* Not matching yet: PAL WIP; main .text 0x00526388, 188B. Not part of the build. */
/*
 * Native copies object a0->a1 and table high part v0->a2; trial keeps object in a0 and one full
 * table base in a1. Native forms table low part again in final class rejection delay; trial uses
 * cached fullbase and NOP there. Both reachable NOPs after earlyzero return and all native
 * conditional read/delay relationships already agree. No remaining branch-graph hypothesis from
 * this experiment.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 9a65a977627bb99c7fc4df6f4fb685a7eebae3d74f15df4b0e085d9208437462
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00526388 nonmatching/pal/game/func_00526388.c --diff
 */
#include "common.h"
extern u8 D_00171DB8[];
extern s32 D_0021DE3C;

u8 func_00526388(void *arg0)
{
    u8 *object = arg0;
    u8 *base = D_00171DB8;
    u8 *secondary;
    s32 field;
    s32 mode;
    s32 kind;

    if (*(base + *(s32 *)(object + 0x2F10) + 0xA8) != 0) {
        goto enabled;
    }
reject:
    return 0;
enabled:
    field = *(s32 *)(object + 0x3F4);
    mode = D_0021DE3C;
    if (field != 0) goto reject;
    if (mode == 2 || mode == 6) goto reject;
    if (*(u8 *)(object + 0x266D) != 0) {
        secondary = *(u8 **)(object + 0x2EFC);
        secondary = *(u8 **)(secondary + 0x50);
        if (secondary != NULL && *(s16 *)(secondary + 0x86) == 5) {
            goto reject;
        }
    }
    kind = *(s32 *)(object + 0x25CC);
    if (kind == 0x71 || kind == 0x31 || kind == 0x1C ||
        kind == 0x8E || kind == 0x8F) goto reject;
    return *(base + *(s32 *)(object + 0x2F10) + 0xA8);
}
