/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_001BCA24;
extern s32 D_001BCC1C;
extern s32 func_01ED5DD0(s32, s32, s32, void *);

s32 func_01ED8450(u8 *obj, s32 arg1, s32 arg2)
{
    obj[0x14] = 0;
    if (D_00169CD0 != 1) {
        return -15;
    }
    if (D_00169CD4 == 0) {
        return -16;
    }
    D_001BCC1C = arg1;
    D_001BCA24 = arg2;
    return func_01ED5DD0(4, 0x2D, 0x1C, obj) == 0 ? 0 : -5;
}
