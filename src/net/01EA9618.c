/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

typedef struct { s32 f0, f4; } Obj;
s32 func_01EA94D0(Obj *, u64);
s32 func_01EA9790(s32 *, s32, u32);
s32 func_01EA9618(Obj *o, u32 size, u16 align) {
    s32 r;
    if (o == 0 || size == 0) {
        return 0x64;
    }
    o->f0 = 0;
    o->f4 = 0;
    if (align >= 2) {
        size += align - 1;
        size += align - size % align;
    }
    r = func_01EA94D0(o, size);
    if (r != 0) {
        return r;
    }
    return func_01EA9790(&o->f4, o->f0, align);
}
