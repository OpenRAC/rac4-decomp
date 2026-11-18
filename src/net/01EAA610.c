/* cflags: @ee296 -O2 -G0 */
#include "common.h"

/* Walks the 0x34-byte records at D_1B23C8 (256 of them), releasing each one whose word at +0x30 is set; then releases D_1B23C8 and the four globals D_00168B90, D_00168B8C, D_00168B88, D_00168B94 that are set, and clears D_00168B84. */
extern s32 func_01EA95C0(s32 *);
extern u8 *D_1B23C8[];
extern s32 D_00168B88[];
extern s32 D_00168B8C[];
extern s32 D_00168B90[];
extern s32 D_00168B94[];
extern s8 D_00168B84[];

s32 func_01EAA610(void) {
    u8 *p;
    s32 s0;
    u32 s1;

    if (D_1B23C8[0] != NULL) {
        s1 = 0;
        s0 = 0;
        do {
            p = (u8 *)((u32)s0 + (u32)D_1B23C8[0]);
            s0 += 0x34;
            if (*(s32 *)(p + 0x30) != 0) {
                func_01EA95C0((s32 *)(p + 0x30));
            }
            s1 += 1;
        } while (s1 < 0x100U);
        func_01EA95C0((s32 *)D_1B23C8);
    }
    if (D_00168B90[0] != 0) {
        func_01EA95C0(D_00168B90);
    }
    if (D_00168B8C[0] != 0) {
        func_01EA95C0(D_00168B8C);
    }
    if (D_00168B88[0] != 0) {
        func_01EA95C0(D_00168B88);
    }
    if (D_00168B94[0] != 0) {
        func_01EA95C0(D_00168B94);
    }
    D_00168B84[0] = 0;
    return 0;
}
