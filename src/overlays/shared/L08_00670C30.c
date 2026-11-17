#include "common.h"

extern void *func_L00_005DEBD0(s32 a, s32 b, s32 c);
extern s32 D_222694;
extern s32 D_2226E0;
extern u16 *D_288A20[];

/* Walks the id list for entry a, running each entry's callback; returns 0 if one fails, else 1. */
s32 func_L08_00670C30(s32 a) {
    u16 *p;
    u8 *s0;
    s32 *cb;

    if (a == -1) {
        return 0;
    }
    p = D_288A20[a];
    if ((a & 0xFF) != 0xFF) {
        if (D_2226E0 < a) {
            return 1;
        }
        if (p == 0) {
            return 1;
        }
        do {
            s0 = (u8 *)D_222694 + ((*p & 0x7FFF) << 8);
            if (s0 == 0) {
                break;
            }
            cb = (s32 *)func_L00_005DEBD0(*(s16 *)(s0 + 0xBC), 0xC, 0x28);
            if (cb != 0) {
                if (((s32 (*)(u8 *))cb[3])(s0) == 0) {
                    return 0;
                }
            }
            p += 1;
            if ((a & 0xFF) == 0xFF) {
                break;
            }
            if (D_2226E0 < a) {
                return 1;
            }
            if (p == 0) {
                return 1;
            }
        } while ((s16)p[-1] >= 0 || p == D_288A20[a]);
    }
    return 1;
}
