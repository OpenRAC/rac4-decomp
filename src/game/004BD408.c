#include "common.h"

extern void func_00499CE0(s32 arg0);
extern s32 func_00505B20(void);
extern void func_00505D30(s32 arg0);
extern u8 D_30A6F0[];

/* Takes the current owner's 0x534-byte slot of D_30A6F0, calls func_00505D30(0xF), then passes its words at 0x10 and 0x14 to func_00499CE0 and zeroes them. */
void func_004BD408(void) {
    u8 *temp_s0;

    temp_s0 = D_30A6F0 + func_00505B20() * 0x534;
    func_00505D30(0xF);
    func_00499CE0(*(s32 *)(temp_s0 + 0x10));
    *(s32 *)(temp_s0 + 0x10) = 0;
    func_00499CE0(*(s32 *)(temp_s0 + 0x14));
    *(s32 *)(temp_s0 + 0x14) = 0;
}
