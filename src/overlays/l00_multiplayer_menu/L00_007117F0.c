#include "common.h"

typedef struct {
    u8 f0[0x60];
    s32 f60;
    char f64[0x40][0x50];
    u8 f1464[0x40];
    u8 f14A4;
    s32 f14A8;
    s32 f14AC;
} Type1;

extern char *func_0011AFC8(char *, char *, s32);

// Copies up to 0x40 names into the menu object's table, clears their flags and resets the selection.
s32 func_L00_007117F0(Type1 *arg0, s32 arg1, char **arg2) {
    s32 i;

    arg0->f60 = arg1;
    if (arg1 > 0x40) {
        arg0->f60 = 0x40;
    }
    for (i = 0; i < arg0->f60; i++) {
        if (arg2[i] != 0) {
            func_0011AFC8(arg0->f64[i], arg2[i], 0x50);
            arg0->f64[i][0x4F] = 0;
            arg0->f1464[i] = 0;
        } else {
            arg0->f64[i][0] = 0;
            arg0->f1464[i] = 0;
        }
    }
    if (arg0->f60 > 0) {
        arg0->f14A8 = 0;
    } else {
        arg0->f14A8 = -1;
    }
    arg0->f14AC = arg0->f14A8;
    return arg0->f60;
}
