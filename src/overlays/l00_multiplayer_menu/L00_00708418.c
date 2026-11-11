#include "common.h"
/* Ported from rac3-decomp's func_L39_0067ED90 (src/levels/39_multiplayer_menu/L39_0067CE08.c, GPL-3.0), the same code in both games. */

typedef struct { int a, b, c; } T;
extern T D_004D7540[];
extern void func_01E9AA78(int, int, int);
void func_L00_00708418(unsigned int i) {
    if (i < 6) func_01E9AA78(D_004D7540[i].a, D_004D7540[i].b, D_004D7540[i].c);
}
