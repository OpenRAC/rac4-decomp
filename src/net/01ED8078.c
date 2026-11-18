/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_1BCB2C;
extern s32 D_1BC934;
extern s32 func_01ED5DD0(s32, s32, s32, void *);

s32 func_01ED8078(u8 *obj, s32 arg1, s32 arg2)
{
    u32 tmp;

    obj[0x14] = 0;
    if (D_00169CD0 != 1) {
        return -15;
    }
    if (D_00169CD4 == 0) {
        return -16;
    }
    tmp = *(u32 *)(obj + 0x18);
    D_1BCB2C = arg1;
    D_1BC934 = arg2;
    if (tmp >= 0x64) {
        *(s32 *)(obj + 0x18) = 0;
    }
    return func_01ED5DD0(4, 0xF, 0x28, obj) == 0 ? 0 : -5;
}
