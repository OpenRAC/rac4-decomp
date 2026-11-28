#include "common.h"

#include "pal/menu_state_00309940.h"
extern f32 func_004760C0(f32 *, f32 target, f32 fraction, f32 minimum);
extern void func_004B6270(void);
extern void func_00502520(void *descriptor);
extern void func_004B5F70(void);
extern void func_004B6140(void);

void func_004B5E30(void *descriptor)
{
    f32 *progress;

    switch (D_00309940[0].phase) {
    case 2:
        progress = &D_00309940[0].progress;
        if (func_004760C0(progress, 1.0f, 0.0f, 0.05f) != 0.0f) {
            goto pending;
        }
        *(s32 *)((u32)progress - 0x1C) = 0;
        break;
    case 1:
        D_00309940[0].phase = 0;
        D_00309940[0].progress = 1.0f;
        break;
    case 4:
        progress = &D_00309940[0].progress;
        if (func_004760C0(progress, 0.0f, 0.0f, 0.05f) != 0.0f) {
        pending:
            func_004B6270();
        } else {
            *(s32 *)((u32)progress - 0x1C) = 3;
        }
        break;
    case 3:
        D_00309940[0].progress = 0.0f;
        func_00502520(descriptor);
        break;
    case 0:
        D_00309940[0].flag25 = 0;
        if (D_00309940[0].update) {
            func_004B5F70();
        }
        func_004B6140();
        break;
    }
}
