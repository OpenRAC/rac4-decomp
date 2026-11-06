#include "common.h"

extern s32 func_00501458(s32 *, s32, s32, s32, s32, s32);
extern char D_0030F490[];
extern char D_0063A120[];
extern char D_0063A158[];
extern char D_0063A1C8[];

s32 D_002227C4 = 0;

/* Initialize the referenced object once and return it. */
void *func_L00_00639FE0(void) {
    if (D_002227C4 == 0) {
        func_00501458((s32 *)D_0030F490, (s32)D_0063A120, (s32)D_0063A158, (s32)D_0063A1C8, 0, 0);
        D_002227C4 = 1;
    }
    return D_0030F490;
}
