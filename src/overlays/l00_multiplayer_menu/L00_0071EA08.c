#include "common.h"

// Ask each of the 11 objects at arg0 + 0xD4 to shut down.
void func_L00_0071EA08(u8 *arg0) {
    s32 **list = (s32 **)(arg0 + 0xD4);
    s32 i;

    *(s32 *)(arg0 + 0x2774) = -1;
    for (i = 0xA; i >= 0; i--) {
        u8 *o = (u8 *)*list++;

        (*(void (**)(u8 *))(*(s32 *)(o + 0x58) + 0xE4))(o);
    }
}
