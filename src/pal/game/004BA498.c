#include "common.h"

typedef struct {
    f32 x;
    f32 y;
} Position;
extern const Position D_003D1E70[];
extern s32 D_002218B0;
extern s32 func_004A2798(s32 *, s32);
extern s32 func_004A1720(s32);
extern s32 func_005052D0(s32, f32, f32);
extern s32 func_00506978(s32, f32, f32);
extern s32 func_005060D8(s32, s32);
extern s32 func_00506000(s32, s32);
extern s32 func_00505F00(s32, s32, s32);
extern s32 func_005063C0(s32, u32);
extern s32 func_00506E68(s32, s32);

void func_004BA498(void)
{
    s32 i;
    const Position *position = D_003D1E70;

    for (i = 0; i < 13; i++, position++) {
        s32 handle = func_004A2798(&D_002218B0, i + 0xB4);

        func_004A1720(handle);
        func_005052D0(handle, position->x, position->y);
        func_00506978(handle, 0.8f, 0.8f);
        func_005060D8(handle, 1);
        func_00506000(handle, 1);
        func_00505F00(handle, 1 + (i <= 4), 3);
        func_005063C0(handle, 0x80D0D0D0);
        func_00506E68(D_002218B0, handle);
    }
}
