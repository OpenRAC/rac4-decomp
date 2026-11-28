#include "common.h"

extern s32 D_00221818;
extern s32 D_003096C0[];
extern s32 func_004A2798(s32 *group, s32 id);
extern s32 func_005052D0(s32 handle, f32 x, f32 y);
extern s32 func_005055E8(s32 handle, f32 *x, f32 *y);
extern s32 func_005056E0(s32 handle, f32 *x, f32 *y);
extern s32 func_005058D8(u32 handle, f32 x1, f32 y1, f32 x2, f32 y2);
extern s32 func_005061B0(u32 handle, s32 x1, s32 y1, s32 x2, s32 y2);

void func_004B1890(void)
{
    f32 coordinates[4];
    f32 x1, y1, x2, y2;
    f32 offset;

    func_005056E0(func_004A2798(&D_00221818, 3), &coordinates[0], &coordinates[1]);
    offset = (f32)D_003096C0[0] * coordinates[1];
    func_005055E8(func_004A2798(&D_00221818, 0x22), &coordinates[2], &coordinates[3]);
    func_005052D0(func_004A2798(&D_00221818, 0x22), coordinates[2], coordinates[3] + offset);
    func_005061B0(func_004A2798(&D_00221818, 2), (s32)&x1, (s32)&y1, (s32)&x2, (s32)&y2);
    func_005058D8(func_004A2798(&D_00221818, 2), x1, y1, x2, y2 + offset);
}
