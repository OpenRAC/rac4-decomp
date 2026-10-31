#include "common.h"

extern void func_00501B48(void *, f32 *, f32 *, f32 *);
extern void func_00501BA0(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern void func_00501BC8(void);

s32 D_00220B04 = 0;

/* Passes the four float arguments to func_00501BA0, after func_00501B48 when the counter D_00220B04 is positive. */
void func_00501D70(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    f32 sp0 = fparg0;
    f32 sp4 = fparg1;
    f32 sp8 = fparg2;
    f32 spC = fparg3;

    if (D_00220B04 > 0) {
        func_00501B48(&sp0, &sp4, &sp8, &spC);
    }
    func_00501BA0(sp0, sp4, sp8, spC);
    func_00501BC8();
}
