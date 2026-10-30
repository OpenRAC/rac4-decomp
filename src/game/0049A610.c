#include "common.h"

extern void func_00497E10(s32);
extern void func_005014B0(s32 *a0);
extern s32 func_00505B20(void);
extern u8 D_306D20[];

/* Look up entry idx of D_306D20 (16 bytes each); if its word at +8 is zero, call func_00497E10 with idx and func_005014B0 with arg0. */
void func_0049A610(s32 arg0) {
    s32 idx;
    s32 *e;

    idx = func_00505B20();
    e = (s32 *)(D_306D20 + idx * 16);
    if (e[2] == 0) {
        func_00497E10(idx);
        func_005014B0((s32 *)arg0);
    }
}
