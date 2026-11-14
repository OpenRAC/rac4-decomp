#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
} Type1;

extern Type1 D_321590[];
extern s32 func_0045E038(s32);

/* Fills the table at D_321590: a handle at each even word, a tag after it, the tags counting down from 5 first. */
void func_004D94F8(void) {
    s32 i;

    i = 5;
    do {
        D_321590[i].f4 = i;
        i -= 1;
    } while (i >= 0);
    D_321590[0].f0 = func_0045E038(0x322A);
    D_321590[0].f4 = 0;
    D_321590[1].f0 = func_0045E038(0x322B);
    D_321590[1].f4 = 1;
    D_321590[2].f0 = func_0045E038(0x322C);
    D_321590[2].f4 = 2;
    D_321590[3].f0 = func_0045E038(0x322D);
    D_321590[3].f4 = 3;
    D_321590[4].f0 = func_0045E038(0x322E);
    D_321590[4].f4 = 4;
    D_321590[5].f0 = func_0045E038(0x322F);
    D_321590[5].f4 = 5;
}
