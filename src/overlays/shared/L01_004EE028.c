#include "common.h"

extern u8 *func_006ACB90(s32);
extern void func_L01_0069E6B0(s32);

// Counts the 4 slots whose byte at arg1 + 0x2B0 or signed byte at arg1 + 0x2C4 is non-zero; when
// all are, sets arg1's byte at +0x43 to 0x14 and calls func_L01_0069E6B0 on the +0x2B8 word of
// func_006ACB90's result.
void func_L01_004EE028(u8 *arg0, u8 *arg1) {
    s32 count = 0;
    u8 *p = arg1 + 0x2C4;
    s32 i = 3;

    do {
        if (p[-0x14] != 0 || *(s8 *)p != 0) {
            count++;
        }
        i--;
        p++;
    } while (i >= 0);
    if (count >= 4) {
        u8 *obj;
        arg1[0x43] = 0x14;
        obj = func_006ACB90(*(s32 *)(arg0 + 0xB8));
        if (obj != NULL) {
            s32 v = *(s32 *)(obj + 0x2B8);
            if (v != 0) {
                func_L01_0069E6B0(v);
            }
        }
    }
}
