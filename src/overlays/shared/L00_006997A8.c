#include "common.h"

extern void func_00501AA0(void);
f32 D_002203DC = 0;
f32 D_002203E0 = 0;

/* Stores the two float arguments into globals D_002203DC and D_002203E0, then calls func_00501AA0. */
void func_L00_006997A8(f32 fparg0, f32 fparg1) {
    D_002203DC = fparg0;
    D_002203E0 = fparg1;
    func_00501AA0();
}
