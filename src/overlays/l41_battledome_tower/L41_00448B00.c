#include "common.h"
void func_L41_00448B00(void *arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = (*(void **)((u8 *)(arg0) + 0xAC));
    if (temp_v0 != NULL) {
        (*(s32 *)((u8 *)(temp_v0) + 0x1C)) = arg1;
    }
}
