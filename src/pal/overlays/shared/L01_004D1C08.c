/* cflags: -Os -G8 -Wuninitialized */
#include "common.h"
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

s32 func_L01_004CA908(s32);                      /* extern */
s32 func_L01_004CA930(s32);                  /* extern */

s32 func_L01_004D1C08(void *arg0) {
    s32 var_2;
    void *temp_17;

    temp_17 = M2C_FIELD(arg0, void **, 0xAC);
    if (M2C_FIELD(temp_17, s32 *, 0x2E0) == 0) {
        return 0;
    }
    var_2 = 0;
    if (func_L01_004CA908((s32)arg0) == 0) {
        func_L01_004CA930((s32)arg0);
        M2C_FIELD(temp_17, s8 *, 0x2DF) = 1;
        var_2 = 1;
    }
    return var_2;
}
