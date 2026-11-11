#include "common.h"
/* Ported from rac3-decomp's func_L39_004CBE68 (src/levels/39_multiplayer_menu/L39_004CA568.c, GPL-3.0), the same code in both games. */

typedef struct Type1 {
    u8 pad0[0x28];
    struct Type1 *f28;
    struct Type1 *f2C;
    u8 pad30[0xC4 - 0x30];
    struct Type1 *fC4;
    struct Type1 *fC8;
} Type1;
void func_L00_00507C68(Type1 *a0, Type1 *a1)
{
    Type1 *next = a1->fC8;
    Type1 *prev;
    if (next != 0 && (prev = a1->fC4) != 0) {
        if (next == (Type1 *)&a0->f2C) {
            if (prev == (Type1 *)&a0->f28) {
                a0->f28 = 0;
                a0->f2C = 0;
            } else {
                a0->f2C = prev;
                a1->fC4->fC8 = next;
            }
        } else if (prev == (Type1 *)&a0->f28) {
            a0->f28 = next;
            a1->fC8->fC4 = prev;
        } else {
            next->fC4 = prev;
            a1->fC4->fC8 = a1->fC8;
        }
        a1->fC8 = 0;
        a1->fC4 = 0;
    }
}
