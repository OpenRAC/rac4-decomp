#include "common.h"

extern void func_00499CE0(s32 arg0);
extern s32 func_00505B20(void);
extern void func_00505D30(s32 arg0);
extern u8 D_320178[];

// Takes the current owner's entry word at +0xC, if set, frees it through func_00499CE0 and clears it.
void func_004D8930(void) {
    s32 temp_a0;
    u8 *entry;

    entry = D_320178 + func_00505B20() * 0x3AC;
    func_00505D30(0xF);
    temp_a0 = *(s32 *)(entry + 0xC);
    if (temp_a0 != 0) {
        func_00499CE0(temp_a0);
        *(s32 *)(entry + 0xC) = 0;
    }
}
