#include "common.h"

extern s32 func_00505B20(void);
extern u8 D_30B7F8[];

/* Set bits 0x76 of word 2 of the table entry chosen by func_00505B20, clearing bit 0. */
void func_004C21A0(void) {
    s32 *entry = (s32 *)(D_30B7F8 + func_00505B20() * 0x74);
    entry[2] = (entry[2] | 0x76) & ~1;
}
