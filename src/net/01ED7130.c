/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 func_01ED5DD0(s32, s32, s32, void *);

/* Clears two flags and runs the request when the network is ready. */
s32 func_01ED7130(u8 *obj)
{
    obj[0x14] = 0;
    obj[0x25] = 0;
    if (D_00169CD0 != 1) {
        return -15;
    }
    if (D_00169CD4 == 0) {
        return -16;
    }
    return func_01ED5DD0(4, 0x16, 0x1C0, obj) == 0 ? 0 : -5;
}
