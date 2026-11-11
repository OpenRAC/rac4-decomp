#include "common.h"

extern void *func_00548D28(s32 arg0, s32 arg1);
extern s32 D_0021EDD4;

f32 func_00548580(s32 arg0) {
    f32 v;

    v = *(f32 *)((u8 *)func_00548D28(arg0, 0) + 0x4C);
    if (D_0021EDD4 == 1) {
        switch (arg0) {
        case 9:
            v = *(f32 *)((u8 *)func_00548D28(7, 0) + 0x4C);
            break;
        case 3:
            v = 1.5f;
            break;
        case 2:
            v = 8.5f;
            break;
        }
    }
    return 1.0f / v;
}
