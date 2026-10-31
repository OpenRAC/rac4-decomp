#include "common.h"

extern s8 D_0021DF88[];
extern s8 D_0021DF90[];
extern s32 D_21DB04;
extern s32 D_21DB00;
extern int func_00126BB0();
void func_001269B0(s32);
void func_001269F0(s32);
void func_001370F8(s32, s32);
s32 func_0012BF10(void *, s32, s32, s32, s32, s32);
s32 func_0012CB20(void *);

/* Runs the init calls once func_0012CB20 on D_0021DF90 succeeds, then polls func_0012BF10 on D_0021DF88 until it returns non-negative. */
void func_00159F78(void) {
    if (func_0012CB20(D_0021DF90) >= 0) {
        func_001370F8(0, 0);
        func_001269F0(D_21DB04);
        func_001269B0(D_21DB04);
        func_00126BB0(D_21DB00);
        do {
        } while (func_0012BF10(D_0021DF88, 0x4402, 0, 0, 0, 0) < 0);
    }
}
