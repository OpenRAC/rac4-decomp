/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_001BC988;
extern s32 D_001BCB80;
extern s32 func_01ED5DD0(s32, s32, s32, void *);

s32 func_01ED4F98(u8 *obj, s32 arg1, s32 arg2)
{
    obj[0x14] = 0;
    obj[0x25] = 0;
    obj[0xF3] = 0;
    if (D_00169CD0 != 1) {
        return -15;
    }
    if (D_00169CD4 == 0) {
        return -16;
    }
    D_001BCB80 = arg1;
    D_001BC988 = arg2;
    return func_01ED5DD0(1, 0x6A, 0xF4, obj) == 0 ? 0 : -5;
}
