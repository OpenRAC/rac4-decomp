#include "common.h"

extern s32 D_172160[];

// Clears the header word at 0x3C, fills the tail of the table with -1 and sets the last two words to -1.
void func_L00_00710080(void) {
    s32 *p;
    s32 *q;
    s32 n;
    s32 m;

    m = -1;
    n = 4;
    D_172160[15] = 0;
    p = D_172160 + 131;
    do {
        *p = m;
        n -= 1;
        p -= 1;
    } while (n >= 0);
    q = D_172160;
    q[132] = -1;
    q[133] = -1;
}
