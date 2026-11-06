#include "common.h"

extern s32 func_00501458(s32 *, s32, s32, s32, s32, s32);
extern char D_00312F40[];
extern char D_006502A8[];
extern char D_00650520[];
extern char D_006505E8[];

s32 D_00222964 = 0;

/* Initialize the referenced object once and return it. */
void *func_L00_00650148(void) {
    if (D_00222964 == 0) {
        func_00501458((s32 *)D_00312F40, (s32)D_006502A8, (s32)D_00650520, (s32)D_006505E8, 0, 0);
        D_00222964 = 1;
    }
    return D_00312F40;
}
