#include "common.h"

extern s32 func_0011D920(s8 *, s8 *, ...);
extern s32 func_0045E038(s32);
extern s32 D_00223188;
extern u8 D_0036CDA8[];
extern s32 D_0036CF88[];

void func_L00_006F8E98(s32 arg0) {
    s32 idx;

    if (D_00223188 < 10) {
        func_0011D920((s8 *)(D_0036CDA8 + D_00223188 * 0x30), (s8 *)func_0045E038(0x1877), arg0);
        idx = D_00223188;
        D_00223188 = idx + 1;
        D_0036CF88[idx] = 0x708;
    }
}
