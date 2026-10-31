#include "common.h"

extern s32 func_00469C40();
extern s32 D_21DA24;
extern s32 D_23F43C[];

// Passes a table entry to func_00469C40 when arg1 rounds up to nonzero, then clears a word in a second table.
void func_004625A0(s32 arg0, s32 arg1) {
    s32 temp_a1;
    s32 base;
    s32 idx;

    temp_a1 = (arg1 + 0xF) & 0xFFFFFFF0;
    if (temp_a1 != 0) {
        base = D_21DA24;
        idx = arg0 + 1;
        func_00469C40(*(s32 *)(base + (idx << 3) + 0x20) + base, temp_a1);
    }
    *(s32 *)(D_23F43C[0] + (arg0 << 2) + 0x74) = 0;
}
