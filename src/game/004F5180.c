#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[0x21 - 0x10];
    u8 f21;
    u8 pad22;
    u8 f23;
    u8 f24;
    u8 f25;
    u8 pad26[0x36 - 0x26];
    s16 f36;
} Type1;

extern Type1 D_00171B40[];

extern s32 func_004F2520(void);
extern void func_004F50D8(s32 a0, s32 a1, s32 a2);

void func_004F5180(void)
{
    s32 n;

    if (D_00171B40[0].fC >= 5000) {
        n = D_00171B40[0].f23;
        if (n >= 2) {
            func_004F50D8(-1, -1, 7);
        }
    }
    if (D_00171B40[0].fC >= 10000) {
        n = D_00171B40[0].f23;
        if (n >= 3) {
            func_004F50D8(-1, -1, 9);
        }
    }
    n = D_00171B40[0].f21;
    if (n > 0) {
        func_004F50D8(-1, -1, 0xD);
    }
    if (D_00171B40[0].fC >= 50000) {
        n = D_00171B40[0].f21;
        if (n >= 2) {
            func_004F50D8(-1, -1, 0xC);
        }
    }
    n = D_00171B40[0].f24;
    if (n > 0) {
        func_004F50D8(-1, -1, 0xE);
    }
    if (D_00171B40[0].fC >= 100000) {
        n = D_00171B40[0].f24;
        if (n >= 2) {
            func_004F50D8(-1, -1, 0xF);
        }
    }
    if (func_004F2520() == 0xB || func_004F2520() == 0x1F) {
        func_004F50D8(-1, -1, 0xA);
    }
    if (D_00171B40[0].fC >= 150000) {
        n = D_00171B40[0].f25;
        if (n >= 2) {
            func_004F50D8(-1, -1, 0x12);
        }
    }
    if (D_00171B40[0].f36 >= 4) {
        func_004F50D8(-1, -1, 0x14);
    }
}
