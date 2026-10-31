#include "common.h"

extern void func_0049B0D8(s32 arg0);
extern void func_0049C200(s32, s32);
extern void func_004D9CD8(void);
extern s32 func_00505B20(void);
extern u8 D_321650[];

/* Clears the flag word of the current owner's entry, then releases it. */
void func_004D98A0(void) {
    s32 temp_v0;
    u8 *entry;

    temp_v0 = func_00505B20();
    entry = D_321650 + temp_v0 * 0x124;
    *(s32 *)(entry + 8) = 0;
    func_004D9CD8();
    func_0049C200(temp_v0, 0);
    func_0049B0D8(temp_v0);
}
