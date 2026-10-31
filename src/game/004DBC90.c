#include "common.h"

extern void func_0049B0D8(s32 arg0);
extern void func_0049C200(s32, s32);
extern void func_004DC178(void);
extern s32 func_00505B20(void);
extern u8 D_322FC8[];

/* Clear the flag word of the slot selected by the current index, then run the reset calls. */
void func_004DBC90(void) {
    u8 *temp_v0;

    temp_v0 = D_322FC8 + func_00505B20() * 0x168;
    *(s32 *)(temp_v0 + 4) = 0;
    func_004DC178();
    func_0049C200(func_00505B20(), 0);
    func_0049B0D8(0);
}
