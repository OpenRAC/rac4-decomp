#include "common.h"

extern s32 func_00501458(s32 *, s32, s32, s32, s32, s32);
extern char D_0030D6D8[];
extern char D_006295C0[];
extern char D_006297D0[];
extern char D_006295C8[];

s32 D_0022264C = 0;

/* Initialize the referenced object once and return it. */
void *func_L00_006294F8(void) {
    if (D_0022264C == 0) {
        func_00501458((s32 *)D_0030D6D8, (s32)D_006295C0, (s32)D_006297D0, (s32)D_006295C8, 0, 0);
        D_0022264C = 1;
    }
    return D_0030D6D8;
}
