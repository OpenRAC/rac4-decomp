#include "common.h"

extern void func_00504F68(s32, s32);

typedef struct {
    s32 f0;
    s32 f4;
    u8 pad8[5];
    u8 fD;
    u8 padE[10];
} Type1;

typedef struct {
    u8 pad0[0x34];
    Type1 *f34;
    u8 pad38[0x18];
    s32 f50;
    s32 f54;
} Type2;

/* Calls func_00504F68 on the second word of each flagged 0x18-byte entry, then clears the count and sets the next word to -1. */
void func_004A1170(Type2 *arg0) {
    s32 i;

    for (i = 0; i < arg0->f50; i++) {
        if (arg0->f34[i].fD != 0) {
            func_00504F68(arg0->f34[i].f4, 0);
        }
    }
    arg0->f50 = 0;
    arg0->f54 = -1;
}
