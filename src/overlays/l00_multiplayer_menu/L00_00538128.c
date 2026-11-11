#include "common.h"
/* Ported from rac3-decomp's func_L39_004FC318 (src/levels/39_multiplayer_menu/L39_004FC318.c, GPL-3.0), the same code in both games. */

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;
void func_L00_00538128(void *p) {
    BitSet_004FCA98 *s = p;
    s32 n = s->f4;
    if (n > 0) {
        unsigned long *e = &s->f0[n - 1];
        if (*e-- == 0) {
            while ((s->f4 = n - 1) > 0 && *e-- == 0) {
                n = s->f4;
            }
        }
    }
}
