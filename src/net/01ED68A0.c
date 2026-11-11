/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_0011D5D8(const char *, ...);
s32 func_01ED5DD0(s32, s32, s32, void *);
extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_001984F8[];
extern s32 D_001B78E0[];

s32 func_01ED68A0(void) {
    func_0011D5D8((const char *)D_001984F8);
    if (D_00169CD0 != 1) return -0xF;
    if (D_00169CD4 == 0) return -0x10;
    return (func_01ED5DD0(1, 0x15, 0x26, D_001B78E0) == 0) ? 0 : -5;
}
