/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_001BC8F8;
extern s32 D_001BCAF0;
extern s32 func_01ED5DD0(s32, s32, s32, void *);

s32 func_01ED6BB0(u8 *obj, s32 arg1, s32 arg2)
{
    obj[0x14] = 0;
    obj[0x25] = 0;
    obj[0x6B] = 0;
    if (D_00169CD0 != 1) {
        return -15;
    }
    if (D_00169CD4 == 0) {
        return -16;
    }
    D_001BCAF0 = arg1;
    D_001BC8F8 = arg2;
    return func_01ED5DD0(1, 0x98, 0x6C, obj) == 0 ? 0 : -5;
}
