/* cflags: -G0 */
/* C adapted from rac3-decomp func_003B3408 (NTSC-U func_003B3268, commit 403f30a9) */
#include "common.h"

extern void *func_005010E0();
extern void func_00501000(void *);
extern u8 D_00223148[];

void func_L00_0061E2D8(void) {
    void *x = D_00223148;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_005010E0();
    }
    func_00501000(x);
}
