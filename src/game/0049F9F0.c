#include "common.h"

extern s32 func_00505B20(void);
extern u8 D_307254[];

/* Reads one byte at arg0 * 12 from the word at 0x3C of the 512-byte entry chosen by func_00505B20(). */
u8 func_0049F9F0(s32 arg0) {
    u8 *p = (u8 *)D_307254 + (func_00505B20() << 9);

    return *(u8 *)(arg0 * 0xC + *(s32 *)(p + 0x3C));
}
