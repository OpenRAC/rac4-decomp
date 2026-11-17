/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01ED5DD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 D_00169CD0[];
extern s32 D_00169CD4[];

/* Clears the flag at offset 0x47, then calls func_01ED5DD0 when both globals are set. */
s32 func_01ED7590(u8 *arg0) {
    arg0[0x47] = 0;
    if (D_00169CD0[0] != 1) {
        return -0xF;
    }
    if (D_00169CD4[0] == 0) {
        return -0x10;
    }
    return (func_01ED5DD0(4, 0x30, 0x180, arg0) == 0) ? 0 : -5;
}
