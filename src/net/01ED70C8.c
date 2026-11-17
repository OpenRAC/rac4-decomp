/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 func_01ED5DD0(s32, s32, s32, void *);

s32 func_01ED70C8(u8 *obj)
{
    obj[0x14] = 0;
    obj[0x25] = 0;
    obj[0x6F] = 0;
    if (D_00169CD0 != 1) {
        return -15;
    }
    if (D_00169CD4 == 0) {
        return -16;
    }
    return func_01ED5DD0(4, 0x23, 0x70, obj) == 0 ? 0 : -5;
}
