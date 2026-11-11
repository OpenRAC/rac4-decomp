#include "common.h"

void func_00473A88(void *object, s32 state, s32 animation);

s32 func_L01_004B3D48(void *);

void func_L01_004B2DC8(void *arg0) {
    s32 temp_v1;
    void *extension;

    extension = *(void **)((u8 *)arg0 + 0xAC);
    if ((*(u8 *)((s8 *)(arg0) + (0x69))) != 6) {
        temp_v1 = (*(s32 *)((s8 *)(extension) + (0x3D0)));
        if (temp_v1 & 4) {
            if (func_L01_004B3D48(arg0) != 0) {
                func_00473A88(arg0, 0xC, 6);
            }
        } else if ((temp_v1 & 1) && (func_L01_004B3D48(arg0) != 0)) {
            func_00473A88(arg0, 0xE, 6);
        }
    }
}
