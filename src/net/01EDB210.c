/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_001BC9D8;
extern s32 D_001BCBD0;
extern s32 func_01ED5DD0(s32, s32, s32, void *);

s32 func_01EDB210(u8 *obj, s32 arg1, s32 arg2)
{
    obj[0xC0] = 0;
    if (D_00169CD0 != 1) {
        return -15;
    }
    if (D_00169CD4 == 0) {
        return -16;
    }
    D_001BCBD0 = arg1;
    D_001BC9D8 = arg2;
    return func_01ED5DD0(1, 0xAC, 0xC4, obj) == 0 ? 0 : -5;
}
