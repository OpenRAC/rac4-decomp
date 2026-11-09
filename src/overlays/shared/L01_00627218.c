#include "common.h"

void *func_L01_0055DC00(s16);

s32 func_L01_00627218(s16 arg0, s32 arg1) {
    u8 *temp_v0;

    temp_v0 = func_L01_0055DC00(arg0);
    if (temp_v0 != NULL) {
        *(s32 *)(temp_v0 + 0x18) = arg1;
    }
    return 1;
}
