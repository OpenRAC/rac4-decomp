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

void func_004654B0(void)
{
    u32 flags;

    if (D_001719C8[0].mode != 2) {
        if (D_0021EE54 == 1 || !D_001719C8[0].pending) {
            func_00465338(4);
        } else {
            D_001719C8[0].pending = 0;
            func_00465338(3);
        }
    } else {
        flags = D_0021DB64;
        if (flags & 4) {
            func_00465338(30);
        } else if (flags & 2) {
            func_00465338(29);
        } else if (!D_0021EE54) {
            if (D_001719C8[0].pending && D_001719C8[0].active) {
                D_001719C8[0].pending = 0;
                func_00465338(3);
            } else if (!D_001719C8[0].pending) {
                func_00465338(5);
            } else if (flags & 0x200) {
                func_00465338(28);
            }
        }
    }
}
