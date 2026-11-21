#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern s32 func_0015B558(void);
extern u8 *D_002233A4;
extern u8 D_172160[];

// Expires the object's two timed flags (+4 and +0x12): each loop flags a failure on error or after 0x3A99 ticks; returns 1 if either run ended cleanly.
s32 func_L00_0076FF18(u8 *arg0) {
    s32 s3 = 1;
    s32 s2;
    s32 r;
    u8 *s0 = D_002233A4;
    u8 *p;
    u8 *q;

    if (arg0[4] != 0) {
        q = D_172160;
        do {
            if (func_0015B558() != 0 || *(s32 *)(q + 0x2C4) != 0) {
                *(s32 *)(s0 + 0x10) = 0x38;
                if (*(s32 *)(s0 + 0x14) == 0) {
                    *(s32 *)(s0 + 0x14) = 0x38;
                }
                s3 = 0;
            }
            s0[0x1C] = 1;
            func_0015A050();
            s0[0x1C] = 0;
            if ((s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(arg0 + 0xC) < 0x3A99) {
                continue;
            }
            s3 = 0;
            break;
        } while (arg0[4] != 0);
    }
    s2 = 1;
    arg0[4] = 0;
    if (arg0[0x12] != 0) {
        p = D_172160;
        do {
            if (func_0015B558() != 0 || *(s32 *)(p + 0x2C4) != 0) {
                *(s32 *)(s0 + 0x10) = 0x38;
                if (*(s32 *)(s0 + 0x14) == 0) {
                    *(s32 *)(s0 + 0x14) = 0x38;
                }
                s2 = 0;
            }
            s0[0x1C] = 1;
            func_0015A050();
            s0[0x1C] = 0;
            if ((s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(arg0 + 0x18) < 0x3A99) {
                continue;
            }
            s2 = 0;
            break;
        } while (arg0[0x12] != 0);
    }
    arg0[0x12] = 0;
    r = 0;
    if (s3 != 0 || s2 != 0) {
        r = 1;
    }
    return r;
}
