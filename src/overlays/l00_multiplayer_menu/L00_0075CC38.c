/* cflags: -mno-split-addresses */
#include "common.h"

s32 D_00221618 = 0;
extern s32 D_00223410[];
extern s32 func_L00_00709318(s32 arg0, s32 arg1, s32 arg2);
extern void func_L00_00709378(s32 arg0, s32 arg1);

void func_L00_0075CC38(void) {
    s32 i;
    s32 j;
    s32 *s = &D_00221618;
    s32 *d = D_00223410;

    for (i = 0; i <= 0; i++) {
        d[i] = func_L00_00709318(s[i], 0, 0);
        for (j = 0; j < 2; j++)
            func_L00_00709378(d[i], j);
    }
}
