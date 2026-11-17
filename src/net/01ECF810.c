/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 *D_00167F38;

/* Walks a list of entries, appends small ones to the output, and recurses into child blocks for the rest. */
void func_01ECF810(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 s5;
    s32 s2;
    s32 idx;
    u8 *s0;

    if (arg0 != NULL) {
        if (arg1 != NULL) {
            s5 = 0;
            if (*(s32 *)(arg1 + 4) > 0) {
                do {
                    s0 = ((u8 **)*(u8 **)(arg1 + 0x28))[s5];
                    if (*(s32 *)(s0 + 0xC) >= 0x10) {
                        if (*(u32 *)(arg0 + 4) >= *(u32 *)(D_00167F38 + 0xFC)) {
                            return;
                        }
                        s2 = 0;
                        if (*(s32 *)(s0 + 8) > 0) {
                            do {
                                s2 += 1;
                                func_01ECF810(arg0, *(u8 **)(D_00167F38 + 0x16C) + *(s32 *)(s0 + 0xC) * 0x30 - 0x300, arg2 + *(s32 *)(s0 + 0));
                            } while (s2 < *(s32 *)(s0 + 8));
                        }
                    } else {
                        ((s32 *)*(u8 **)(arg0 + 0x2C))[*(s32 *)(arg0 + 4)] = arg2 + *(s32 *)(s0 + 0);
                        idx = *(s32 *)(arg0 + 4);
                        *(s32 *)(arg0 + 4) = idx + 1;
                        ((u8 **)*(u8 **)(arg0 + 0x28))[idx] = s0;
                    }
                    s5 += 1;
                } while (s5 < *(s32 *)(arg1 + 4));
            }
        }
    }
}
