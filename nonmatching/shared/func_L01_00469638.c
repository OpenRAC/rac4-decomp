/* Not matching yet: BYTES 6/60 (tools/try_func.py func_L01_00469638 --diff). Not part of the build. */
#include "common.h"

void func_L01_00469638(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0xAC);
    u8 *s = p + 0x47C;
    s32 i;
    p[0x501] = 0;
    i = 5;
    do {
        u8 c = *s;
        i--;
        if (c == 0) goto next;
        if (c == 9) p[0x501] = 1;
next:
        ;
    } while (i >= 0 && (s++, 1));
}
