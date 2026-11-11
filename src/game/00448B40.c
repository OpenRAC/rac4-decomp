#include "common.h"

typedef struct Display {
    u8 fields[0x150];
    s16 width;
    s16 height;
} Display;

extern Display D_00206A40;
extern char *func_00448A20(s32 index);

void func_00448B40(s32 index, s32 *left, s32 *top, s32 *right, s32 *bottom)
{
    f32 *rectangle = (f32 *)func_00448A20(index);

    *left = (s32)((f32)D_00206A40.width * rectangle[0]);
    *top = (s32)((f32)D_00206A40.height * rectangle[2]);
    *right = (s32)((f32)D_00206A40.width * rectangle[1]);
    *bottom = (s32)((f32)D_00206A40.height * rectangle[3]);
}
