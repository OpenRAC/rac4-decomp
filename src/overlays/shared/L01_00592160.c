#include "common.h"

/* Count the entries of list arg0 whose object passes the arg1 filter and the arg2 test through func_L00_005EAC30. */
extern void *func_L00_005EAC30(void *);
extern s32 D_222D14;
extern u16 *D_28BFE0[];

s32 func_L01_00592160(s32 arg0, s32 arg1, s32 arg2) {
    u16 *s0;
    u16 *tbl;
    u8 *o;
    f32 *f;
    s32 count;

    if (arg0 == -1 || arg0 == 0xFF) {
        return 0;
    }
    count = 0;
    tbl = D_28BFE0[arg0];
    if (tbl == NULL) {
        return 0;
    }
    {
        f32 zero = 0.0f;
        s0 = tbl;
        for (;;) {
            o = (u8 *)(((*s0 & 0x7FFF) << 8) + D_222D14);
            if ((s8)o[0x20] >= 0 && (arg1 == -1 || (u8)o[0x20] != arg1)) {
                if (arg2 != 0) {
                    f = func_L00_005EAC30(o);
                    if (f == NULL || zero < *f) {
                        count++;
                    }
                } else {
                    count++;
                }
            }
            if ((s16)*s0 < 0) {
                break;
            }
            s0 += 1;
        }
    }
    return count;
}
