/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 D_00222B28[];
extern s32 func_00452958(void *, void *, s32);

void func_L01_004337D0(u8 *arg0) {
    u8 *p;
    if (arg0 != 0) {
        u8 s = arg0[0x20];
        if (s != 0xFE) {
            if (s != 0xFD) {
                p = *(u8 **)(arg0 + 0xAC);
                if (p != 0) {
                    func_00452958(D_00222B28, p + 0x40, *(s32 *)(p + 0x10));
                }
            }
        }
    }
}
