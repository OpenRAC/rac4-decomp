#include "common.h"

extern s32 D_0039DCB0[];
extern s32 D_0039DCC8[];
extern s32 D_0039DCE0[];
extern void func_L01_00513E78();

s32 D_00220D40 = 0;
s32 D_00220D44 = 0;
s32 D_00220D48 = 0;

// Initialise the state block on first use (state 0), then run func_L01_00513E78 unless the block's +0x140 is set.
void func_L14_003E9A90(u8 *arg0) {
    s32 *block = *(s32 **)(arg0 + 0xAC);

    if (block[0x140 / 4] == 0) {
        if (arg0[0x20] == 0) {
            arg0[0x20] = 1;
            block[0x14 / 4] = (s32)D_0039DCB0;
            block[0x10 / 4] = (s32)D_0039DCC8;
            block[0xC / 4] = 4;
            block[0x4 / 4] = D_00220D40;
            block[0x18 / 4] = D_00220D44;
            block[0x1C / 4] = D_00220D48;
            block[0x8 / 4] = (s32)D_0039DCE0;
            block[0] = 0;
            block[0x20 / 4] = D_00220D44;
        }
        func_L01_00513E78(arg0);
    }
}
