/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern u8 D_00220A30;
extern s32 D_00220A34;
extern s32 D_003F2358[];

/* Resolve a slot index and fetch its fields through optional out pointers. */
s32 func_L00_007098D8(s32 idx, s32 *a, s32 *b, void **c, void **d) {
    s32 ok = 0;
    s32 slot = -1;
    u8 *p;
    if (D_00220A30 != 0 && idx < 0x40) {
        slot = (D_00220A34 + idx) % 64;
    } else if (idx < D_00220A34) {
        slot = idx;
    }
    if (slot >= 0) {
        p = (u8 *)D_003F2358 + slot * 0x68;
        ok = 1;
        if (a != 0) *a = *(s32 *)p;
        if (b != 0) *b = *(s32 *)(p + 4);
        if (c != 0) *c = p + 8;
        if (d != 0) *d = p + 0x58;
    }
    return ok;
}
