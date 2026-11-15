#include "common.h"

typedef struct {
    u8 f0;
    u8 pad1[7];
    s32 f8;
    u8 pad12[8];
} Type1;

extern void func_L00_0070C528(s32 *a0, s32 a1, s32 a2);
extern Type1 D_003F3F78[];

/* Clears the 0x46 slots, then resets entries 1..15 of the table. */
void func_L00_0070CE18(s32 *a0) {
    s32 i;

    for (i = 0; i < 0x46; i++) {
        func_L00_0070C528(a0, i, 0);
    }
    for (i = 1; i < 16; i++) {
        D_003F3F78[i].f0 = 0;
        D_003F3F78[i].f8 = 0;
    }
}
