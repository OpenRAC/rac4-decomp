#include "common.h"

typedef struct Type1 {
    char p0[0x3C];
    s16 f3C;
    s16 f3E;
    char p40[0x48 - 0x40];
    s16 f48;
    char p4A[0x4E - 0x4A];
    s16 f4E;
    char p50[0xC6 - 0x50];
    s16 fC6;
} Type1;

extern Type1 D_00206948[];

void func_L00_005FF120(s32 arg0, s32 arg1) {
    if (D_00206948[0].f48 == arg0 && D_00206948[0].f3C == -1) {
        return;
    }
    if (arg0 != -1) {
        arg0 &= 0xFF;
    }
    if (arg1 != -1) {
        arg0 &= 0xFF;
    }
    if (D_00206948[0].f4E == 0 && D_00206948[0].fC6 == 0) {
        D_00206948[0].f48 = arg0;
        return;
    }
    D_00206948[0].f3C = arg0;
    D_00206948[0].f3E = arg1;
}
