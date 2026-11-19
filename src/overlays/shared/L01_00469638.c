#include "common.h"

void func_L01_00469638(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0xAC);
    u8 *s = p + 0x47C;
    s32 tag = 9;
    s32 one = 1;
    s32 i;
    p[0x501] = 0;
    i = 5;
    do {
        u8 c = *s;
        i--;
        if (c == 0) goto next;
        if (c == tag) p[0x501] = one;
next:
        ;
    } while (i >= 0 && (s++, 1));
}
