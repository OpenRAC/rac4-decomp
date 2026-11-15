#include "common.h"

typedef struct {
    s32 f0;
    u8 pad[0x28];
} Type1;

extern Type1 D_003B1738[];
extern s32 D_172160[];
extern s32 D_00220B0C;

// Copies five words from D_172160 + 0x1FC into D_003B1738 at a 0x2C-byte stride, then stores the word at D_172160 + 0x214 into D_00220B0C.
void func_L00_007100D0(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        D_003B1738[i].f0 = D_172160[127 + i];
    }
    D_00220B0C = D_172160[133];
}
