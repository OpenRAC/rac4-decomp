/* Not matching yet: BYTES 20/176 (tools/try_func.py func_L00_0075CC38 --diff). Not part of the build. */
#include "common.h"

s32 D_00221618 = 0;
extern s32 D_00223410[];
extern s32 func_L00_00709318(s32 arg0, s32 arg1, s32 arg2);
extern void func_L00_00709378(s32 arg0, s32 arg1);

void func_L00_0075CC38(void) {
    s32 i;
    s32 j;

    for (i = 0; i <= 0; i++) {
        D_00223410[i] = func_L00_00709318((&D_00221618)[i], 0, 0);
        for (j = 0; j < 2; j++)
            func_L00_00709378(D_00223410[i], j);
    }
}
