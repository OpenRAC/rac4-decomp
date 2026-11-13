#include "common.h"

extern s32 func_00505B20(void);

typedef struct Type1 {
    char pad[8];
    s32 f8;
    char pad2[0x28];
} Type1;

typedef struct Type2 {
    char pad[0xB2C];
    s32 fB2C;
} Type2;

extern Type1 D_0030D038[];
extern Type2 D_0030B9D8[];
extern u8 D_001F87F0[];

/* Scan five entries for one whose bit 1 at +8 is set under the current slot. */
s32 func_004C6868(void)
{
    Type2 *history = D_0030B9D8 + func_00505B20();
    s32 found = -1;
    s32 i;
    s32 slot = history->fB2C - 1;

    for (i = 0; i < 5; i++) {
        s32 m = slot % 20;
        s32 offset = D_0030D038[i].f8 * 12 + m * 0x304;
        s32 flag = D_001F87F0[offset + 8];
        if ((flag >> 1) & 1) {
            found = i;
        }
    }
    return found;
}
