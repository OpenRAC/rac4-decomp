#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    char pad[0x20];
} Type1;

extern Type1 D_003B1738[];

/* Sums f8 over the five entries whose f0 is not -1. */
s32 func_L00_0070D508(void) {
    Type1 *p;
    s32 sum;

    sum = 0;
    p = D_003B1738;
    do {
        if (p->f0 != -1) {
            sum += p->f8;
        }
        p++;
    } while ((s32)p < (s32)(D_003B1738 + 5));
    return sum;
}
