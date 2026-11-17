/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01ED5DD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 D_00169CD0[];
extern s32 D_00169CD4[];

/* Clears the flag at offset 0x10, then calls func_01ED5DD0 when both globals are set. */
s32 func_01ED6258(u8 *arg0) {
    if (D_00169CD0[0] != 1) {
        return -0xF;
    }
    if (D_00169CD4[0] == 0) {
        return -0x10;
    }
    arg0[0x10] = 0;
    return (func_01ED5DD0(1, 0x49, 0x18, arg0) == 0) ? 0 : -5;
}
