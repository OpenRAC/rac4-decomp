#include "common.h"

typedef struct State {
    u8 unknown0[8];
    s32 mode;
    u32 unknownC;
    s32 active;
    u8 unknown14[0x1D0];
    s32 pending;
} State;

extern State D_001719C8[];
extern s32 D_0021EE54;
extern u32 D_0021DB64;
extern void func_00465338(s32 state);

void func_004655A0(void)
{
    if (D_001719C8[0].mode != 2) {
        func_00465338(4);
    } else if (!D_0021EE54 && D_001719C8[0].pending) {
        func_00465338(1);
    } else if (D_0021DB64 & 4) {
        func_00465338(30);
    } else if (D_0021DB64 & 2) {
        func_00465338(29);
    } else if (D_0021DB64 & 0x800) {
        func_00465338(12);
    } else if (D_001719C8[0].mode == 2 && D_001719C8[0].active) {
        func_00465338(5);
    }
}
