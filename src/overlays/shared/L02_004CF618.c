#include "common.h"

extern void func_00559410(u8 *object, s32 a1, s32 a2);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern s32 func_L01_005A4648(const u8 *owner);
extern void func_L02_004CF6A0();

// Dispatch on the state byte at +0x20: state 0 runs func_L02_004CF6A0, state 1 finishes the object.
void func_L02_004CF618(u8 *object) {
    s32 state = object[0x20];

    if (state != 1) {
        if (state < 2) {
            if (state == 0) {
                func_L02_004CF6A0();
            }
        }
    } else {
        if (object[0xBE] & 4) {
            func_L01_005A4648(object);
            func_L01_00591BD8(object, 2, -1);
        }
        func_00559410(object, 0x11, -1);
    }
}
