#include "common.h"
typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
} Type1;

/* Fills the first free slot among two records. */
void func_00520F30(char *a, s32 b, s32 c, s32 d)
{
    Type1 *p = (Type1 *)(a + 0x2D20);
    s32 i = 0;
    do {
        i++;
        if (!p->f0) {
            p->f0 = 1;
            p->f6 = d;
            p->f4 = c;
            p->f2 = b;
            return;
        }
        p++;
    } while (i < 2);
}
