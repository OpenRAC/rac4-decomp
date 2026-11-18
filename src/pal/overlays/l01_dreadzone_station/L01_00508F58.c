#include "common.h"

void func_L01_005B0178(void *object, f32 x, f32 y, f32 z);
void func_00474368(void *object, s32 state, s32 arg);

s32 func_L01_00508F58(void *object, s32 event)
{
    switch (event) {
        case 1:
            func_L01_005B0178(object, 0.0f, 15.0f, 30.0f);
            break;

        case 4:
            func_00474368(object, 1, 0);
            break;
    }

    return 1;
}
