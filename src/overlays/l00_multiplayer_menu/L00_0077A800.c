#include "common.h"

typedef void (*Func1)(s32, s32);

extern s32 D_004EEB68[];
extern u8 *D_004EEB90[];

// Dispatch to the handler of entry arg1 in table arg0 when it is in range.
void func_L00_0077A800(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *tab;

    if (arg0 < 9) {
        tab = D_004EEB90[arg0];
        if (arg1 < D_004EEB68[arg0]) {
            (*(Func1 *)(tab + arg1 * 12 + 4))(arg2, arg3);
        }
    }
}
