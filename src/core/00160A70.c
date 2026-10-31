#include "common.h"

extern u8 D_00172160[];
extern s32 D_21DBF0;
extern u8 D_2126B8[];
extern void func_01E9E270(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, void *t1);
/* Calls func_01E9E270 with the flags byte of D_00172160 when the word at 0x258 is zero. */
void func_00160A70(s32 arg0) {
    u8 *base;

    base = D_00172160;
    if (*(s32 *)(base + 0x258) == 0) {
        func_01E9E270(base[0x7F8] | 0x40, *(s32 *)(base + 8), arg0, D_21DBF0, 0x58, D_2126B8);
    }
}
