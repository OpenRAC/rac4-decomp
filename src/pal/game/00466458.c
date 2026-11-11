#include "common.h"

typedef struct State {
    u8 pad0[0x10];
    s32 x10;
    u8 pad14[0x19C];
    s32 x1B0;
} State;

extern State D_001719C8;
extern s32 D_0021DB64;
extern u8 D_00222500;
extern u8 D_00222508;
s32 D_0021EA98 = 0;
s32 D_0021EA9C = 0;
s32 D_0021EAA0 = 0;
s32 D_0021EAA4 = 0;
s32 D_0021EAA8 = 0;
s32 D_0021EAAC = 0;

extern void func_L00_005D99B0(void);
extern s32 func_004662F8(s32 a);

// Switch on the request mode (1 to 7): records the arguments in D_0021EA98..D_0021EAAC, clears the state in D_001719C8 and updates the flags in D_0021DB64.
s32 func_00466458(s32 mode, s32 a, s32 b, s32 c) {
    s32 r;
    s32 f;
    s32 m1;
    s32 m2;
    s32 m3;

    r = 0;
    switch (mode) {
    case 1:
    case 2:
        D_0021EAAC = a;
        D_0021EA98 = b;
        D_0021EA9C = c;
        D_001719C8.x1B0 = 0;
        D_0021EAA0 = 0;
        D_0021EAA4 = 0;
        D_0021EAA8 = 0;
        D_00222508 = 0;
        D_00222500 = 0;
        func_L00_005D99B0();
        D_001719C8.x10 = 0;
        D_0021DB64 &= ~4;
        D_0021DB64 |= 2;
        D_0021DB64 &= ~0x10;
        D_0021DB64 &= ~0x4000;
        if (mode == 2) {
            D_0021DB64 |= 0x4000;
        }
        break;
    case 3:
        D_0021EAA4 = c;
        D_001719C8.x1B0 = 0;
        D_001719C8.x10 = 0;
        D_0021EAA0 = b;
        D_0021EAAC = a;
        D_0021EA98 = 0;
        D_0021EA9C = 0;
        D_0021EAA8 = 0;
        D_00222508 = 0;
        func_L00_005D99B0();
        D_00222500 = 1;
        D_0021DB64 |= 4;
        D_0021DB64 &= ~2;
        D_0021DB64 &= ~0x10;
        D_0021DB64 &= ~0x4000;
        break;
    case 4:
        r = func_004662F8(a);
        if (r != 0) {
            D_0021EAA8 = c;
            D_0021DB64 |= 0x10;
            D_0021DB64 &= ~4;
            D_0021DB64 &= ~2;
            D_001719C8.x1B0 = 0;
            D_001719C8.x10 = 0;
            D_0021EA98 = 0;
            D_0021EA9C = 0;
            D_0021EAA0 = 0;
            D_0021EAA4 = 0;
            D_00222508 = 0;
            D_00222500 = 0;
            func_L00_005D99B0();
        }
        break;
    case 6:
        D_001719C8.x1B0 = 0;
        D_0021DB64 |= 0x800;
        break;
    case 5:
        D_0021DB64 |= 8;
        break;
    case 7:
        D_0021DB64 |= 0x200;
        break;
    }
    return r;
}
