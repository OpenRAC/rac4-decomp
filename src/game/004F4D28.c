#include "common.h"

extern void func_00464038(int index);
extern void func_004E7450(u8 *);
extern void func_004F25D8(s32 arg0);
extern void func_004F47A0();
extern void func_004F4B88();
extern s32 D_001170D0[];
extern s32 D_0021EDD4;
extern s32 D_1DFC54[];
extern u8 D_237000[];
s32 D_0022095C = 0;

/* Advance the poll counters at D_237000 and report whether the counter branch ran. */
s32 func_004F4D28(void) {
    s32 var_s1;
    u8 *s0;
    s32 temp_v0;
    s32 temp_a0;

    func_004E7450(D_001170D0);
    if (D_0021EDD4 == 1) {
        return 0;
    }
    var_s1 = 0;
    s0 = D_237000;
    *(s32 *)(s0 + 0x78) = *(s32 *)(s0 + 0x78) + 1;
    temp_v0 = *(s32 *)(s0 + 0x74) + 1;
    *(s32 *)(s0 + 0x74) = temp_v0;
    if (temp_v0 == 1) {
        func_004F25D8(D_1DFC54[0]);
    }
    if (*(s16 *)(s0 + 0x80) >= *(s32 *)(s0 + 0x74)) {
        if (*(s32 *)(s0 + 0x78) >= 0x60) {
            temp_a0 = *(s32 *)(s0 + 0x7C) + 1;
            *(s32 *)(s0 + 0x7C) = temp_a0;
            func_00464038(temp_a0);
        }
        func_004F47A0();
        func_004F4B88();
    } else {
        var_s1 = 1;
        D_0022095C = D_0022095C + 1;
    }
    return var_s1;
}
