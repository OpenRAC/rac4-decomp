#include "common.h"

extern int func_005B4F70(void *, int);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);

// Handles state 4: sets the flags in the sub-object, clears the word at 0x98 and notifies the actor with state 2.
s32 func_L01_004B8BD8(u8 *object, s32 arg1) {
    u8 *state = *(u8 **)(object + 0xAC);

    if (arg1 == 4) {
        *(s16 *)(state + 0x5EA) = -1;
        state[0x611] = 1;
        *(s32 *)(object + 0x98) = 0;
        func_005B4F70(object, 0);
        func_L01_00591BD8(object, 2, 2);
    }
    return 1;
}
