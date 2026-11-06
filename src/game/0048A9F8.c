#include "common.h"
typedef struct {
    u32 f0;
    u8 pad4[3];
    u8 f7;
    u8 pad8[2];
    u8 fA;
    u8 padB[0x14 - 0xB];
    s32 f14;
    u8 pad18[8];
    f32 f20;
    f32 f24;
    s32 f28;
    s32 f2C;
} Type1;
/* Resets a record: word 0 to 0xFFFFFFFF, the floats at +0x20 and +0x24 to 1.0, and the
 * words and bytes at +0x14, +0x28, +0x2C, +7 and +0xA to 0. */
void func_0048A9F8(void *unused, Type1 *t) {
    t->f20 = 1.0f;
    t->f24 = 1.0f;
    t->f0 = 0xFFFFFFFF;
    t->f28 = 0;
    t->f2C = 0;
    t->f7 = 0;
    t->fA = 0;
    t->f14 = 0;
}
