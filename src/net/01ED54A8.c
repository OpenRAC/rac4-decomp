/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01ED5DD0(s32 arg0, s32 arg1, s32 arg2, void *arg3);

extern s32 D_00169CD0[];
extern s32 D_00169CD4[];
extern s32 D_1BC9C8[];
extern s32 D_1BCBC0[];

s32 func_01ED54A8(void *arg0, s32 arg1, s32 arg2) {
    s32 v;

    *(unsigned char *)((char *)arg0 + 0x14) = 0;
    if (D_00169CD0[0] != 1) {
        return -0xF;
    }
    if (D_00169CD4[0] == 0) {
        return -0x10;
    }
    v = *(s32 *)((char *)arg0 + 0x1C);
    D_1BCBC0[0] = arg1;
    D_1BC9C8[0] = arg2;
    if ((unsigned int)v >= 0x64U) {
        *(s32 *)((char *)arg0 + 0x1C) = 0;
    }
    return func_01ED5DD0(1, 0xDA, 0x24, arg0) ? -5 : 0;
}
