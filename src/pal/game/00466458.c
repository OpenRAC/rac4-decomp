#include "common.h"

typedef struct State {
    u8 pad0[0x10];
    s32 x10;
    u8 pad14[0x19C];
    s32 x1B0;
} State;

extern State D_001719C8;
extern s32 D_0021DB64;
extern u8 D_002214E0;
extern u8 D_002214E8;
s32 D_0021F1D8 = 0;
s32 D_0021F1DC = 0;
s32 D_0021F1E0 = 0;
s32 D_0021F1E4 = 0;
s32 D_0021F1E8 = 0;
s32 D_0021F1EC = 0;

extern void func_00466760(void);
extern s32 func_004662F8(s32 a);

// Switch on the request mode (1 to 7): records the arguments in D_0021F1D8..D_0021F1EC, clears the state in D_001719C8 and updates the flags in D_0021DB64.
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
        D_0021F1EC = a;
        D_0021F1D8 = b;
        D_0021F1DC = c;
        D_001719C8.x1B0 = 0;
        D_0021F1E0 = 0;
        D_0021F1E4 = 0;
        D_0021F1E8 = 0;
        D_002214E8 = 0;
        D_002214E0 = 0;
        func_00466760();
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
        D_0021F1E4 = c;
        D_001719C8.x1B0 = 0;
        D_001719C8.x10 = 0;
        D_0021F1E0 = b;
        D_0021F1EC = a;
        D_0021F1D8 = 0;
        D_0021F1DC = 0;
        D_0021F1E8 = 0;
        D_002214E8 = 0;
        func_00466760();
        D_002214E0 = 1;
        D_0021DB64 |= 4;
        D_0021DB64 &= ~2;
        D_0021DB64 &= ~0x10;
        D_0021DB64 &= ~0x4000;
        break;
    case 4:
        r = func_004662F8(a);
        if (r != 0) {
            D_0021F1E8 = c;
            D_0021DB64 |= 0x10;
            D_0021DB64 &= ~4;
            D_0021DB64 &= ~2;
            D_001719C8.x1B0 = 0;
            D_001719C8.x10 = 0;
            D_0021F1D8 = 0;
            D_0021F1DC = 0;
            D_0021F1E0 = 0;
            D_0021F1E4 = 0;
            D_002214E8 = 0;
            D_002214E0 = 0;
            func_00466760();
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
