#include "common.h"

typedef struct {
    s32 f0;
    u8 pad[0x28];
} Type1;

extern Type1 D_003B1738[];
extern s32 D_172160[];
s32 D_00220B0C = 0;
s32 D_00220B1C = 0;

// Copies five words from D_003B1738 at a 0x2C-byte stride into D_172160 + 0x1FC,
// then sets the last two words from D_00220B0C and D_00220B1C.
void func_L00_00710110(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        D_172160[127 + i] = D_003B1738[i].f0;
    }
    D_172160[133] = D_00220B0C;
    D_172160[132] = D_00220B1C;
}
