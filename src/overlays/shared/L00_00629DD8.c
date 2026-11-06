#include "common.h"

extern s32 func_00501458(s32 *, s32, s32, s32, s32, s32);
extern char D_0030D708[];
extern char D_00629EC0[];
extern char D_0062A100[];
extern char D_00629EC8[];

s32 D_00222654 = 0;

/* Initialize the referenced object once and return it. */
void *func_L00_00629DD8(void) {
    if (D_00222654 == 0) {
        func_00501458((s32 *)D_0030D708, (s32)D_00629EC0, (s32)D_0062A100, (s32)D_00629EC8, 0, 0);
        D_00222654 = 1;
    }
    return D_0030D708;
}
