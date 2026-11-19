#include "common.h"

void func_L01_0050A1A8(void *object);
void func_L01_005ABD28(void *object, f32 x, f32 y);
void func_L01_0050A250(void);
void func_00480FB8(
    void *object,
    s32 mode,
    void (*callback)(void),
    s32 arg3,
    s32 arg4,
    s32 arg5,
    f32 value
);
void func_00473A88(void *object, s32 state, s32 arg);

void func_L01_0050A310(void *object, s32 flag, f32 *vector)
{
    f32 scale;

    if (flag == 0) {
        func_L01_0050A1A8(object);

        scale = 0.0166666675f;

        func_L01_005ABD28(
            object,
            vector[0] * scale,
            vector[1] * scale
        );

        func_00480FB8(
            object,
            2,
            func_L01_0050A250,
            0,
            0,
            0,
            0.0f
        );

        func_00473A88(object, 0x18, 0x6);
    }
}
