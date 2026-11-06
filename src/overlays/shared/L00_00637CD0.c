#include "common.h"

extern s32 func_00501458(s32 *, s32, s32, s32, s32, s32);
extern char D_0030F398[];
extern char D_00637EA0[];
extern char D_00637EE8[];
extern char D_00637F50[];

s32 D_002227A4 = 0;

/* Initialize the referenced object once and return it. */
void *func_L00_00637CD0(void) {
    if (D_002227A4 == 0) {
        func_00501458((s32 *)D_0030F398, (s32)D_00637EA0, (s32)D_00637EE8, (s32)D_00637F50, 0, 0);
        D_002227A4 = 1;
    }
    return D_0030F398;
}
