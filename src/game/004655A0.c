#include "common.h"

typedef struct State {
    u8 unknown0[8];
    s32 mode;
    u32 unknownC;
    s32 active;
    u8 unknown14[0x1D0];
    s32 pending;
} State;

extern State D_00171948[];
extern s32 D_0021EDD4;
extern u32 D_0021DAE4;
extern void func_00464AF8(s32 state);

void func_004655A0(void)
{
    if (D_00171948[0].mode != 2) {
        func_00464AF8(4);
    } else if (!D_0021EDD4 && D_00171948[0].pending) {
        func_00464AF8(1);
    } else if (D_0021DAE4 & 4) {
        func_00464AF8(30);
    } else if (D_0021DAE4 & 2) {
        func_00464AF8(29);
    } else if (D_0021DAE4 & 0x800) {
        func_00464AF8(12);
    } else if (D_00171948[0].mode == 2 && D_00171948[0].active) {
        func_00464AF8(5);
    }
}
