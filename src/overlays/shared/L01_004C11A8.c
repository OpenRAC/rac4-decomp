#include "common.h"

extern s32 func_005AF4B8(void *);
extern void func_L01_00591C18(u8 *object, s32 new_state, s32 param);

/* Return 0 unless the object is in a state that allows it and the linked record has a pending value at +0x1E0; then switch the object to state 6 or 7. */
s32 func_L01_004C11A8(u8 *arg0)
{
    u8 state = arg0[0x20];
    u8 *linked = *(u8 **)(arg0 + 0xAC);
    s32 mode;

    if (state != 16 && state != 14 && state != 15 && state != 17) {
        if (func_005AF4B8(arg0) == 0) {
            mode = *(s32 *)(linked + 0x410);
            if (mode != 1) {
                if (mode != 4) {
                    return 0;
                }
                if (*(s32 *)(linked + 0x1E0) == 0) {
                    return 0;
                }
                func_L01_00591C18(arg0, 6, -1);
                return 1;
            } else {
                if (*(s32 *)(linked + 0x1E0) == 0) {
                    return 0;
                }
                func_L01_00591C18(arg0, 7, -1);
                return 1;
            }
        }
    }
    return 0;
}
