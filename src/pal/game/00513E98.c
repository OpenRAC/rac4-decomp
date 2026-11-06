#include "common.h"

extern s32 func_0051C2B0(u8 *, f32);
extern void func_00513E28(u8 *, u8, s32, s32, s32);

// Switch on the byte at +0x54 of the structure at +0x2EF0: each group tests
// func_0051C2B0 at two values and calls func_00513E28 for each that passes.
void func_00513E98(u8 *p) {
    u8 id;

    if (*(s32 *)(p + 0x25D4) != 1) {
        return;
    }
    if (*(s32 *)(p + 0x25CC) == 2 && *(s32 *)(p + 0x370) < 12) {
        return;
    }
    id = p[0x43B];
    if (*(s32 *)(p + 0x25CC) == 2 && *(s32 *)(p + 0x370) == 18) {
        func_00513E28(p, id, 0, 1, 30);
    }
    switch ((*(u8 **)(p + 0x2EF0))[0x54]) {
    case 5:
    case 6:
        if (func_0051C2B0(p, 38.5f)) {
            func_00513E28(p, id, 0, 1, 30);
        }
        if (func_0051C2B0(p, 12.0f)) {
            func_00513E28(p, id, 1, 1, 30);
        }
        break;
    case 7:
    case 86:
    case 92:
    case 94:
    case 96:
        if (func_0051C2B0(p, 12.0f)) {
            func_00513E28(p, id, 0, 1, 30);
        }
        if (func_0051C2B0(p, 1.0f)) {
            func_00513E28(p, id, 1, 1, 30);
        }
        break;
    case 8:
    case 91:
    case 93:
    case 95:
    case 97:
        if (func_0051C2B0(p, 8.0f)) {
            func_00513E28(p, id, 0, 1, 30);
        }
        if (func_0051C2B0(p, 21.0f)) {
            func_00513E28(p, id, 1, 1, 30);
        }
        break;
    }
}
