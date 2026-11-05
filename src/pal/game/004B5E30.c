#include "common.h"

typedef struct State {
    s32 unknown00, phase;
    u8 prefix08[0x18];
    f32 progress;
    u8 unknown24, flag25;
    u8 middle26[6];
    u8 update;
} State;
extern State D_00309940;
extern f32 D_00309960[];
extern f32 func_004760C0(f32 *, f32 target, f32 fraction, f32 minimum);
extern void func_004B6270(void);
extern void func_00502520(void *descriptor);
extern void func_004B5F70(void);
extern void func_004B6140(void);

void func_004B5E30(void *descriptor)
{
    f32 *progress;

    switch (D_00309940.phase) {
    case 2:
        progress = D_00309960;
        if (func_004760C0(progress, 1.0f, 0.0f, 0.05f) != 0.0f) {
            goto pending;
        }
        *(s32 *)((u32)progress - 0x1C) = 0;
        break;
    case 1:
        D_00309940.phase = 0;
        D_00309940.progress = 1.0f;
        break;
    case 4:
        progress = D_00309960;
        if (func_004760C0(progress, 0.0f, 0.0f, 0.05f) != 0.0f) {
        pending:
            func_004B6270();
        } else {
            *(s32 *)((u32)progress - 0x1C) = 3;
        }
        break;
    case 3:
        D_00309940.progress = 0.0f;
        func_00502520(descriptor);
        break;
    case 0:
        D_00309940.flag25 = 0;
        if (D_00309940.update) {
            func_004B5F70();
        }
        func_004B6140();
        break;
    }
}
