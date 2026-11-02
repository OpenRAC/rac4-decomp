/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

extern void *D_0021DFF0;

s32 func_L41_00411570(void *arg0) {
    s32 temp_4;
    s32 var_5;

    temp_4 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xAC), s32 *, 0xFC);
    var_5 = 0;
    if ((temp_4 == 0) || (temp_4 & M2C_FIELD(D_0021DFF0, s8 *, 0x14))) {
        var_5 = 1;
    }
    return var_5;
}
