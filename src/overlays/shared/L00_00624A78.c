#include "common.h"

void func_L00_0069C340(s32, void *, f32 *);
void func_L00_0069C438(s32, f32 *, f32 *);
void func_006248F0(s32, s32, f32, f32, f32, f32);

// Read two float pairs for the source (func_L00_0069C340 and func_L00_0069C438) and
// pass them with the two other arguments to func_006248F0.
void func_L00_00624A78(s32 param_a, s32 param_b, s32 source) {
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;

    func_L00_0069C340(source, &x0, &y0);
    func_L00_0069C438(source, &x1, &y1);
    func_006248F0(param_a, param_b, x0, y0, x1, y1);
}
