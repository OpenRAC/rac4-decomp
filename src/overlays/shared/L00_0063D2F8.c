#include "common.h"

extern s32 func_00501458(s32 *, s32, s32, s32, s32, s32);
extern char D_0030F678[];
extern char D_0063D430[];
extern char D_0063D538[];
extern char D_0063D578[];

s32 D_002227F4 = 0;

/* Initialize the referenced object once and return it. */
void *func_L00_0063D2F8(void) {
    if (D_002227F4 == 0) {
        func_00501458((s32 *)D_0030F678, (s32)D_0063D430, (s32)D_0063D538, (s32)D_0063D578, 0, 0);
        D_002227F4 = 1;
    }
    return D_0030F678;
}
