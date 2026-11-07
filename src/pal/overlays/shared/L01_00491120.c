#include "common.h"
typedef long long s128;

void func_00474368(void *object, s32 state, s32 animation);

s32 func_L01_0056E400(s32);

s32 func_L01_00491120(void *arg0, s32 arg1, s32 arg2) {
    u8 temp_v1;
    void *temp_v1_2;
    void *object_owner;
    s32 nativeObjectValue;

    if ((func_L01_0056E400(arg2) != 0) && ((temp_v1 = (*(u8 *)((s8 *)(arg0) + (0x20))), (temp_v1 == 1)) || (temp_v1 == 4))) {
        temp_v1_2 = (*(void **)((s8 *)(arg0) + (0xAC)));
        (*(s128 *)((s8 *)(arg0) + (0x10))) = (s128) (*(s128 *)((s8 *)(temp_v1_2) + (0)));
        (*(s32 *)((s8 *)(temp_v1_2) + (0x10))) = arg1;
        (*(s32 *)((s8 *)(temp_v1_2) + (0x14))) = arg2;
        (*(s8 *)((s8 *)(arg0) + (0x31))) = 1;
        (*(u16 *)((s8 *)(arg0) + (0x34))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x34))) & 0xFFFE);
        object_owner = (*(void **)((s8 *)(arg0) + (0x24)));
        nativeObjectValue = (*(s32 *)((s8 *)(object_owner) + (0x10)));
        (*(s8 *)((s8 *)(arg0) + (0x23))) = 0;
        (*(s32 *)((s8 *)(arg0) + (0x98))) = nativeObjectValue;
        func_00474368(arg0, 3, -1);
        return 1;
    }
    return 0;
}
