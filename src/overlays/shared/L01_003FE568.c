#include "common.h"

extern void func_L01_00400E28(void *);
extern void func_L01_00400FE8(void *, s32);
extern s32 D_0021E824;
extern s32 D_0021E828;

void func_L01_003FE568(u8 *arg0, u8 *arg1, u8 *arg2) {
    u8 *state;
    u8 *p;
    s32 i;

    arg0[0x20] = 0;
    state = *(u8 **)(arg0 + 0xAC);
    if (arg1[0x17D] == 0 || arg1[0x17D] == 3) {
        func_L01_00400E28(arg0);
    }
    *(s32 *)(state + 0x224) = 0;
    if (arg2 != 0 && (D_0021E824 != 0 || D_0021E828 != 1)) {
        p = arg2 + 0x1D;
        if (D_0021E824 != 1) {
            for (i = 0; i < 6; i++) {
                if (p[i] == 9) {
                    func_L01_00400FE8(arg0, 0);
                    i = 6;
                }
            }
        }
    }
}
