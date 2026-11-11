#include "common.h"

void func_L01_005ABDE8(void *object, f32 x, f32 y, f32 z);
void func_L01_00591BD8(void *object, s32 state, s32 arg);

s32 func_L01_004E36C8(void *object, s32 event)
{
    switch (event) {
        case 1:
            func_L01_005ABDE8(object, 0.0f, 15.0f, 30.0f);
            break;

        case 4:
            func_L01_00591BD8(object, 1, 0);
            break;
    }

    return 1;
}
