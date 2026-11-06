#include "common.h"

extern s32 func_00501458(s32 *, s32, s32, s32, s32, s32);
extern char D_00328D80[];
extern char D_00663BE0[];
extern char D_00663CA8[];
extern char D_00663D00[];

s32 D_00222C14 = 0;

/* Initialize the referenced object once and return it. */
void *func_L00_00663AB0(void) {
    if (D_00222C14 == 0) {
        func_00501458((s32 *)D_00328D80, (s32)D_00663BE0, (s32)D_00663CA8, (s32)D_00663D00, 0, 0);
        D_00222C14 = 1;
    }
    return D_00328D80;
}
