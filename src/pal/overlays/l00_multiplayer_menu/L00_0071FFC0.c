#include "common.h"

extern s32 func_L00_0069F6B8(s32, f32, f32);
extern s32 func_L00_0069FB20(s32, f32 *, f32 *);

// Reads a position with func_L00_0069FB20 and moves it by (x, y) with func_L00_0069F6B8.
void func_L00_0071FFC0(s32 arg0, f32 x, f32 y) {
    f32 pos[2];

    pos[1] = pos[0] = 0.0f;
    func_L00_0069FB20(arg0, &pos[0], &pos[1]);
    pos[0] += x;
    pos[1] += y;
    func_L00_0069F6B8(arg0, pos[0], pos[1]);
}
