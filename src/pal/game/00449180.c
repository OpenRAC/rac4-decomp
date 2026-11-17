#include "pal/display_00206AC0.h"
extern char *func_00449060(s32 index);

void func_00449180(s32 index, s32 *left, s32 *top, s32 *right, s32 *bottom)
{
    f32 *rectangle = (f32 *)func_00449060(index);

    *left = (s32)((f32)D_00206AC0.width * rectangle[0]);
    *top = (s32)((f32)D_00206AC0.height * rectangle[2]);
    *right = (s32)((f32)D_00206AC0.width * rectangle[1]);
    *bottom = (s32)((f32)D_00206AC0.height * rectangle[3]);
}
