#include "common.h"

extern s32 D_36E050[];

// Reset the 16-entry table: id -1, two zeros, and a kind of 10.
void func_L41_00625590(void) {
    s32 i;
    s32 *p = D_36E050;
    for (i = 0; i < 16; i++) {
        p[0] = -1;
        p[1] = 0;
        p[2] = 0;
        p[3] = 10;
        p += 4;
    }
}
