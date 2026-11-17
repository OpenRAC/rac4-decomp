/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0xF8]; u32 fF8; char _pfc[0x5C]; s32 *f158, *f15C, *f160; } Ctx;
extern Ctx *D_00167F38;
s32 func_01ECFBD8(u32 i, s32 a, s32 b, s32 c) {
    if (i >= D_00167F38->fF8) {
        return 0x17;
    }
    D_00167F38->f158[i] = a;
    D_00167F38->f15C[i] = b;
    D_00167F38->f160[i] = c;
    return 0;
}
