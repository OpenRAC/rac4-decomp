#include "common.h"

extern s32 func_00501458(s32 *, s32, s32, s32, s32, s32);
extern char D_0030D7F0[];
extern char D_0062A928[];
extern char D_0062AD40[];
extern char D_0062AD90[];

s32 D_00222688 = 0;

/* Initialize the referenced object once and return it. */
void *func_L00_0062A8C8(void) {
    if (D_00222688 == 0) {
        func_00501458((s32 *)D_0030D7F0, (s32)D_0062A928, (s32)D_0062AD40, (s32)D_0062AD90, 0, 0);
        D_00222688 = 1;
    }
    return D_0030D7F0;
}
