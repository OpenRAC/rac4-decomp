#include "common.h"

typedef struct State {
    u32 unknown0[2];
    s32 mode;
    u32 unknownC;
    s32 active;
} State;

extern State D_00171948[];
s32 D_0021DADC = 0;
extern u32 D_0021DAE4;
extern void func_00464AF8(s32 state);

void func_00464F98(void)
{
    s32 mode = D_00171948[0].mode;

    if (mode != 2) {
        func_00464AF8(4);
    } else if (D_00171948[0].active) {
        func_00464AF8(5);
    } else if (D_0021DADC == mode) {
        func_00464AF8(7);
    } else if (D_0021DADC == 1) {
        D_0021DAE4 |= 8;
        func_00464AF8(9);
    }
}
