#include "common.h"

extern u8 D_003D6458[];

/* Clears the used flag and the halfword at offset 6 of the eight 16-byte entries of a block chosen by the argument's indices (block 0 when the argument is NULL). */
void func_00438F58(s32 arg0, void *arg1) {
    s32 idx = 0;
    s32 n;
    u8 *p;

    if (arg1 != NULL) {
        u8 t = ((u8 *)arg1)[0x558];
        if (t == 0xFF) {
            return;
        }
        idx = ((u8 *)arg1)[0x54C] * 4 + t;
    }
    n = 7;
    p = D_003D6458 + (idx << 7);
    do {
        n -= 1;
        if (p[1] != 0) {
            p[1] = 0;
            *(s16 *)(p + 6) = 0;
        }
        p += 0x10;
    } while (n >= 0);
}
