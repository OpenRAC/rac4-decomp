/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern u8 D_002211A8;
extern u8 D_002211A9;
extern u16 *D_002211AC;

s16 func_L00_0073FB98(s32 arg0) {
    s32 var_v1 = 0;
    u16 temp_v1;

    if (D_002211A8 != 0) {
        temp_v1 = D_002211AC[arg0];
        var_v1 = (s16)temp_v1;
        if (D_002211A9 != 0) {
            var_v1 = ((var_v1 & 0xFF) << 8) | ((u32)temp_v1 << 16 >> 24);
        }
    }
    return var_v1;
}
