#include "common.h"

extern s32 D_2211CC;
void func_00516AB8(s32, s32, s32);

// Calls func_00516AB8 six times with arg0, the index 0 to 5, and D_2211CC.
void func_00525C58(s32 arg0) {
    s32 i;

    i = 0;
    do {
        func_00516AB8(arg0, i, D_2211CC);
        i += 1;
    } while (i < 6);
}
