#include "common.h"

extern s32 func_00501458(s32 *, s32, s32, s32, s32, s32);
extern char D_0030CCB0[];
extern char D_00623110[];
extern char D_006231A8[];
extern char D_006231B0[];

s32 D_00222638 = 0;

/* Initialize the referenced object once and return it. */
void *func_L00_00622C80(void) {
    if (D_00222638 == 0) {
        func_00501458((s32 *)D_0030CCB0, (s32)D_00623110, (s32)D_006231A8, (s32)D_006231B0, 0, 0);
        D_00222638 = 1;
    }
    return D_0030CCB0;
}
