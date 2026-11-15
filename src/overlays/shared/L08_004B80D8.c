#include "common.h"

extern u8 *D_222694;
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);

// Switch an object to state 3 unless it is already there; return whether it changed.
s32 func_L08_004B80D8(u8 *arg0, s32 arg1) {
    s32 state = 3;
    s32 *list = (s32 *)(*(u8 **)(arg0 + 0xAC) + 0x10);
    u8 *obj = D_222694 + (list[arg1] << 8);

    if (obj[0x20] != state) {
        func_L01_00591BD8(obj, state, -1);
        return 1;
    }
    return 0;
}
