#include "common.h"

typedef struct {
    u8 pad0[0x50];
    s16 f50;
    s16 f52;
    u8 pad54[0x24];
    s16 f78;
    s16 f7A;
    u8 pad7C[0x4C];
    s16 fC8;
    s16 fCA;
} Type1;

extern Type1 D_206948;

// Copies ARG0 into the s16 after each field that has bit 0x8000 set.
void func_00489498(s32 arg0) {
    if (D_206948.f50 & 0x8000) {
        D_206948.f52 = arg0;
    }
    if (D_206948.fC8 & 0x8000) {
        D_206948.fCA = arg0;
    }
    if (D_206948.f78 & 0x8000) {
        D_206948.f7A = arg0;
    }
}
