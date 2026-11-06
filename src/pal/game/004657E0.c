#include "common.h"

typedef struct State {
    u32 unknown0[2];
    s32 mode;
    u32 unknownC;
    s32 active;
} State;

extern State D_001719C8[];
s32 D_0021DB5C = 0;
extern u32 D_0021DB64;
extern void func_00465338(s32 state);

void func_004657E0(void)
{
    s32 mode = D_001719C8[0].mode;

    if (mode != 2) {
        func_00465338(4);
    } else if (D_001719C8[0].active) {
        func_00465338(5);
    } else if (D_0021DB5C == mode) {
        func_00465338(7);
    } else if (D_0021DB5C == 1) {
        D_0021DB64 |= 8;
        func_00465338(9);
    }
}
