#include "common.h"

typedef int u128 __attribute__((mode(TI)));

s32 func_00472518(void *arg0, s32 arg1, s32 arg2);
s32 func_004740C8(void *, void *, s32);
s32 func_00477D18(u128 arg0, s32 arg1, s32 arg2);
s32 func_00477E10(u128 arg0, s32 arg1, s32 arg2);
s32 func_004FE318(u128 arg0, void *arg1);

extern u8 *D_00221378;
extern s32 *D_0026F640[];

typedef struct {
    u8 pad0[0x10];
    s16 n10;
    s16 n12;
    s16 n14;
    s16 n16;
    s32 pad18;
    s32 *l1C;
    s32 *l20;
    s32 *l24;
    s32 *l28;
} Type1;

s32 func_0047BA40(u128 arg0, s32 arg1) {
    Type1 *e;
    s32 off;
    s32 i;
    s32 *p;

    if (arg1 < 0 || arg1 >= *(s32 *)D_00221378) {
        return 0;
    }
    off = arg1 * 0x30 + 0x20;
    if (func_004FE318(arg0, D_00221378 + off) == 0) {
        return 0;
    }
    e = (Type1 *)(D_00221378 + off);
    for (i = 0; i < e->n12; i++) {
        if (func_00472518(&arg0, e->l20[i], 0)) {
            return 1;
        }
    }
    for (i = 0; i < e->n14; i++) {
        if (func_00477E10(arg0, e->l24[i], 0)) {
            return 1;
        }
    }
    for (i = 0; i < e->n16; i++) {
        if (func_00477D18(arg0, e->l28[i], 0)) {
            return 1;
        }
    }
    for (i = 0; i < e->n10; i++) {
        p = D_0026F640[e->l1C[i]];
        if (func_004740C8(&arg0, p + 4, *p)) {
            return 1;
        }
    }
    return 0;
}
