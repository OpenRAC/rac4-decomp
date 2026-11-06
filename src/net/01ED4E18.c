/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_001BC990;
extern s32 D_001BCB88;
extern s32 func_01ED5DD0(s32, s32, s32, void *);

s32 func_01ED4E18(u8 *obj, s32 arg1, s32 arg2)
{
    obj[0x14] = 0;
    obj[0x25] = 0;
    obj[0xED] = 0;
    if (D_00169CD0 != 1) {
        return -15;
    }
    if (D_00169CD4 == 0) {
        return -16;
    }
    D_001BCB88 = arg1;
    D_001BC990 = arg2;
    return func_01ED5DD0(1, 0x6E, 0xEE, obj) == 0 ? 0 : -5;
}
