#include "common.h"

extern u8 D_395320[];

// Look up an object by the message's grid bytes and, if live, set its +0xBC mode.
s32 func_L01_0040F040(s32 arg0, s32 arg1, s32 arg2, u8 *msg) {
    u8 *object = *(u8 **)(D_395320 + msg[0] * 4 + msg[2] * 0x18);
    u8 *state;
    u8 mode;

    if (object != 0 && object[0x20] != 0xFE && object[0x20] != 0xFD) {
        state = *(u8 **)(object + 0xAC);
        mode = msg[1];
        if (state[0xBC] == 0 || mode == 2) {
            state[0xBC] = mode;
        }
    }
    return 3;
}
