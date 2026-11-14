#include "common.h"

/* Add a word and propagate carry through at most 128 little-endian words. */
void func_01EACF60(u32 *p, u32 add) {
    u32 i = 0;

    goto check;
next:
    i++;
    p++;
check:
    if (i >= 0x80) return;
    if (i != 0) {
        *p += 1;
        if (*p == 0) goto next;
        return;
    }
    *p += add;
    if (*p < add) goto next;
}
