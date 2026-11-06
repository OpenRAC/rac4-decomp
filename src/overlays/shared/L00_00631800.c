#include "common.h"

extern s32 func_00501458(s32 *, s32, s32, s32, s32, s32);
extern char D_0030E1E8[];
extern char D_00631860[];
extern char D_00631868[];
extern char D_006318A0[];

s32 D_002226EC = 0;

/* Initialize the referenced object once and return it. */
void *func_L00_00631800(void) {
    if (D_002226EC == 0) {
        func_00501458((s32 *)D_0030E1E8, (s32)D_00631860, (s32)D_00631868, (s32)D_006318A0, 0, 0);
        D_002226EC = 1;
    }
    return D_0030E1E8;
}
