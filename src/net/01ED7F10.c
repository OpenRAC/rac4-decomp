/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_001BC928;
extern s32 D_001BCB20;
extern s32 func_01ED5DD0(s32, s32, s32, void *);

s32 func_01ED7F10(u8 *obj, s32 arg1, s32 arg2)
{
    obj[0x14] = 0;
    if (D_00169CD0 != 1) {
        return -15;
    }
    if (D_00169CD4 == 0) {
        return -16;
    }
    D_001BCB20 = arg1;
    D_001BC928 = arg2;
    return func_01ED5DD0(1, 0xDC, 0x1C, obj) == 0 ? 0 : -5;
}
