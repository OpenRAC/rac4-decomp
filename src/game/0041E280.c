#include "common.h"

extern void func_00547FF8(s32, s32, s32);
extern void func_00415F40(s32, u8 *, s32);
extern u8 *func_00548D28(s32, s32);
extern s32 func_0054A788(s32, s32, s32);
extern void func_00473A88(u8 *, s32, s32);

void func_0041E280(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    u8 *v;
    f32 speed;
    s32 n;
    s32 id;

    if (*(u8 **)(vars + 0xC) != NULL) {
        id = *(s32 *)(vars + 0);
        func_00547FF8(*(s32 *)(*(u8 **)(vars + 0xC) + 0x26E4), 6, 1);
        func_00415F40(id, *(u8 **)(vars + 0xC), 1);
        v = *(u8 **)(moby + 0xAC);
        speed = *(f32 *)(func_00548D28(6, 0) + 0x4C);
        n = func_0054A788(*(s32 *)(*(u8 **)(v + 0xC) + 0x26E4), 6, 1);
        if (n != 0) {
            speed *= 1.0f - n * 0.05f;
        }
        speed *= 2.0f;
        *(s16 *)(v + 6) = (*(s16 *)(v + 4) = speed * 60.0f) * 0.85f;
        *(f32 *)(*(u8 **)(v + 0xC) + 0x3EC) = speed;
        *(s32 *)(vars + 0) = 0;
        func_00473A88(moby, 6, -1);
    }
}
