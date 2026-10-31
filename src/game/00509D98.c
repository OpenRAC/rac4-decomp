#include "common.h"

/* If the object supports D_00220B68 (checked with the method at +0x14 of its +8 table), call func_0050EE68 with the object and the float and return 1; otherwise return 0. */
extern void func_0050EE68(void *arg0, f32 fparg0);
extern s32 D_00220B68;

s32 func_00509D98(void *arg0, f32 fparg0) {
    u8 *object = arg0;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(arg0, D_00220B68) != 0) {
        func_0050EE68(arg0, fparg0);
        return 1;
    }
    return 0;
}
