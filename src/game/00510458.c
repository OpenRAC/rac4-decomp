#include "common.h"

typedef struct {
    u8 pad0[0x34];
    f32 f34;
    f32 f38;
    u8 pad3C[0x4];
    u16 f40;
    u8 pad42[0xE];
    u8 f50;
} Type2;

typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    f32 f20;
    u8 pad24[0x1C];
    Type2 *f40;
    u8 pad44[0x4];
    f32 f48;
    f32 f4C;
} Type1;

extern void func_00454350(s32);
extern void func_0050F080(Type1 *);
extern void func_0050F438(Type1 *, f32 *, f32, f32);

// Pick a mode by the state byte, then update the two axes when flagged.
s32 func_00510458(Type1 *arg0) {
    Type2 *p;

    switch (arg0->f40->f50) {
    case 1:
        func_00454350(1);
        break;
    case 2:
        func_00454350(0);
        break;
    case 0:
    default:
        func_00454350(0);
        break;
    }
    if (arg0->f40->f40 & 4) {
        func_0050F080(arg0);
        p = arg0->f40;
        if (p->f40 & 0x80) {
            func_0050F438(arg0, &p->f34, arg0->f1C, arg0->f48);
        } else {
            func_0050F438(arg0, &p->f38, arg0->f20, arg0->f4C);
        }
    }
    return 0;
}
