#include "common.h"

typedef struct Inner {
    char pad0[0x335];
    u8 f5AA;
} Inner;

typedef struct Outer {
    char pad0[0xAC];
    Inner *inner;
} Outer;

s32 func_L04_0049F3F8(Outer *arg0) {
    return arg0->inner->f5AA == 0;
}
