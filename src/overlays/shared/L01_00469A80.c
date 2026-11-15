#include "common.h"

extern void func_L00_005F6AE0(void *, s32, s32, s32, s32, s32, f32);
extern void func_L01_00469250(void *arg0);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);

// Handle event 4: start the state change or fall back to the default action.
s32 func_L01_00469A80(u8 *object, s32 event) {
    u8 *state = *(u8 **)(object + 0xAC);
    if (event == 4) {
        if (state[0x504] != 0) {
            func_L00_005F6AE0(object, 0xB, 0, 0, 0, 0, 0.0f);
            func_L01_00591BD8(object, 0x18, -1);
        } else {
            func_L01_00469250(object);
        }
    }
    return 1;
}
