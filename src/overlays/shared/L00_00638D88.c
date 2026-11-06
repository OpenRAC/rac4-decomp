#include "common.h"

extern s32 func_00501458(s32 *, s32, s32, s32, s32, s32);
extern char D_0030F438[];
extern char D_00638F10[];
extern char D_00638F50[];
extern char D_00638FB8[];

s32 D_002227B4 = 0;

/* Initialize the referenced object once and return it. */
void *func_L00_00638D88(void) {
    if (D_002227B4 == 0) {
        func_00501458((s32 *)D_0030F438, (s32)D_00638F10, (s32)D_00638F50, (s32)D_00638FB8, 0, 0);
        D_002227B4 = 1;
    }
    return D_0030F438;
}
