#include "common.h"

typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
} Type1;
typedef struct {
    u8 pad0[0x43B];
    u8 f43B;
    u8 pad43C[0x2D20 - 0x43C];
    Type1 f2D20[2];
} Type2;
s32 func_L00_005BC9B8(void *);
void func_L00_006AD518(void *, u8, s32, s32, s32);
void func_L00_006C68E0(void *, s16, s16);
/* For each of the two 8-byte slots at +0x2D20 whose check returns 2, clear it and dispatch on its kind. */
void func_L00_006C69F0(Type2 *arg0) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (func_L00_005BC9B8(&arg0->f2D20[i].f4) == 2) {
            arg0->f2D20[i].f0 = 0;
            if (arg0->f2D20[i].f2 == 0x1C) func_L00_006AD518(arg0, arg0->f43B, 1, 1, 0x32);
            else func_L00_006C68E0(arg0, arg0->f2D20[i].f2, arg0->f2D20[i].f6);
        }
    }
}
