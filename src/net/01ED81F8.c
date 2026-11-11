/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_1BC940;
extern s32 D_1BCB38;
extern s32 func_01ED5DD0(s32, s32, s32, void *);

/* Clear the state byte and start the 4/0xD/0x20 job once the two flags allow
   it; -15, -16 and -5 are the refusal codes. */
s32 func_01ED81F8(u8 *obj, s32 arg1, s32 arg2)
{
    obj[0x14] = 0;
    if (D_00169CD0 != 1) {
        return -15;
    }
    if (D_00169CD4 == 0) {
        return -16;
    }
    D_1BCB38 = arg1;
    D_1BC940 = arg2;
    return func_01ED5DD0(4, 0xD, 0x20, obj) == 0 ? 0 : -5;
}
