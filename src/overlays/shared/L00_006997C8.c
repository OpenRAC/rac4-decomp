#include "common.h"

extern void func_00501AA0(void);
f32 D_002203F4 = 0;
f32 D_002203F8 = 0;

/* Stores the two float arguments into globals D_002203F4 and D_002203F8, then calls func_00501AA0. */
void func_L00_006997C8(f32 fparg0, f32 fparg1) {
    D_002203F4 = fparg0;
    D_002203F8 = fparg1;
    func_00501AA0();
}
