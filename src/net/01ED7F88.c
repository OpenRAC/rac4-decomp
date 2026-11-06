/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_001BC92C;
extern s32 D_001BCB24;
extern s32 func_01ED5DD0(s32, s32, s32, void *);

s32 func_01ED7F88(u8 *obj, s32 arg1, s32 arg2)
{
    obj[0x14] = 0;
    if (D_00169CD0 != 1) {
        return -15;
    }
    if (D_00169CD4 == 0) {
        return -16;
    }
    D_001BCB24 = arg1;
    D_001BC92C = arg2;
    return func_01ED5DD0(4, 0x37, 0x1A, obj) == 0 ? 0 : -5;
}
