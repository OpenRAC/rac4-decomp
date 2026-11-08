#include "common.h"

void func_00474368(void *object, s32 state, s32 animation);

s32 func_L05_004E1110(void *arg0, s32 arg1) {
    s32 temp_v0;
    void *temp_v1;

    temp_v1 = (*(void **)((s8 *)(arg0) + (0xAC)));
    if (((*(s32 *)((s8 *)(temp_v1) + (0x140))) == 0) && ((temp_v0 = (*(s32 *)((s8 *)(temp_v1) + (0x144))), (temp_v0 == 0)) || (temp_v0 == arg1))) {
        (*(s32 *)((s8 *)(temp_v1) + (0x144))) = arg1;
        if ((*(u8 *)((s8 *)(arg0) + (0x20))) != 6) {
            func_00474368(arg0, 3, -1);
        }
        return 1;
    }
    return 0;
}
