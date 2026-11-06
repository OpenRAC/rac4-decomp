#include "common.h"

extern s32 func_00501458(s32 *, s32, s32, s32, s32, s32);
extern char D_00321770[];
extern char D_0065C9C0[];
extern char D_0065CBC0[];
extern char D_0065CC70[];

s32 D_00222A84 = 0;

/* Initialize the referenced object once and return it. */
void *func_L00_0065C728(void) {
    if (D_00222A84 == 0) {
        func_00501458((s32 *)D_00321770, (s32)D_0065C9C0, (s32)D_0065CBC0, (s32)D_0065CC70, 0, 0);
        D_00222A84 = 1;
    }
    return D_00321770;
}
