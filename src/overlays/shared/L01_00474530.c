#include "common.h"

typedef struct Inner {
    char pad0[0xE];
    u8 fE;
    u8 fF;
} Inner;

typedef struct Outer {
    char pad0[0xAC];
    Inner *fAC;
} Outer;

extern void func_L01_00626818(void *a, s32 b);

void func_L01_00474530(Outer *o) {
    Inner *inner = o->fAC;
    inner->fE = 0;
    inner->fF = 0;
    func_L01_00626818(o, 1);
}
