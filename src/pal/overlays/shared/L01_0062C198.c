#include "common.h"

void *func_004546C8(s16);

s32 func_L01_0062C198(s16 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_004546C8(arg0);
    if (temp_v0 != NULL) {
        (*(s32 *)((s8 *)(temp_v0) + (0x18))) = arg1;
    }
    return 1;
}
