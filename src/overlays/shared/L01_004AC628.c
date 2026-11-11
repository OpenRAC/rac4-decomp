#include "common.h"

void func_00473A88(void *object, s32 state, s32 animation);

s32 func_L01_005A2F40(void *, void *);

void func_L01_004AC628(void *arg0) {
    u8 temp_v1;
    u8 temp_v1_2;
    void *temp_a1;

    temp_v1 = (*(u8 *)((s8 *)(arg0) + (0x69)));
    temp_a1 = (*(void **)((s8 *)(arg0) + (0xAC)));
    switch (temp_v1) {
    case 0:
        if (((*(u8 *)((s8 *)(temp_a1) + (0x632))) == 0) && ((*(s32 *)((s8 *)(temp_a1) + (0x418))) >= 0)) {
            func_00473A88(arg0, 3, 1);
            return;
        }
        if (func_L01_005A2F40(arg0, temp_a1 + 0x310) != 0) {
            func_00473A88(arg0, 5, 2);
            return;
        }
    case 1:
        return;
    case 2:
        if (((*(s32 *)((s8 *)(temp_a1) + (0x334))) < 0) && (temp_v1_2 = (*(u8 *)((s8 *)(arg0) + (0x20))), ((temp_v1_2 == 5) || (temp_v1_2 == 7)))) {
            func_00473A88(arg0, 1, 0);
        }
        break;
    }
}
