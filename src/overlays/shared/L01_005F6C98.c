#include "common.h"

extern s32 func_0065A150(s32 a, s32 b);
extern s32 func_L00_006294E0(void *a, s32 b);
extern s32 D_223098[];
extern s32 D_331880[];

/* Clamps a to >= 0 and, if it differs from the stored value, stores it and notifies. */
void func_L01_005F6C98(s32 a) {
    if (a <= 0) {
        a = 0;
    }
    if (a != D_331880[6]) {
        D_331880[6] = a;
        func_0065A150(func_L00_006294E0(D_223098, 6), D_331880[6]);
    }
}
