#include "common.h"

extern s32 func_00501458(s32 *, s32, s32, s32, s32, s32);
extern char D_0030F628[];
extern char D_0063CCC8[];
extern char D_0063CD58[];
extern char D_0063CDC0[];

s32 D_002227E4 = 0;

/* Initialize the referenced object once and return it. */
void *func_L00_0063CB10(void) {
    if (D_002227E4 == 0) {
        func_00501458((s32 *)D_0030F628, (s32)D_0063CCC8, (s32)D_0063CD58, (s32)D_0063CDC0, 0, 0);
        D_002227E4 = 1;
    }
    return D_0030F628;
}
