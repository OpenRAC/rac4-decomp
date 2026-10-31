#include "common.h"

extern s32 func_00505B20(void);
extern void func_0049B0D8(s32 arg0);
extern void func_0049C200(s32, s32);
extern void func_004D8930(void);
extern u8 D_320178[];

// Clears the +8 word of the current owner's entry, then runs the three cleanup calls.
void func_004D8658(void) {
    s32 owner;
    u8 *entry;

    owner = func_00505B20();
    entry = D_320178 + owner * 0x3AC;
    *(s32 *)(entry + 8) = 0;
    func_004D8930();
    func_0049C200(owner, 0);
    func_0049B0D8(owner);
}
