#include "common.h"

// Calls the two helpers, clears the two counters and the word at 0x10, and re-arms the timer at 0x1CC once it has run out.
extern void *func_004A2358(void);
extern void func_00501498(s32 *arg0);
extern s32 func_00505C90(s32 arg0);
extern u8 D_00171948[];

s32 D_0021F670 = 0;
s32 D_0021F674 = 0;

void func_004A23C0(void) {
    u8 *p;

    func_00501498(func_004A2358());
    func_00505C90((s32)func_004A2358());
    D_0021F670 = 0;
    D_0021F674 = 0;
    p = D_00171948;
    *(s32 *)(p + 0x10) = 0;
    if (*(s32 *)(p + 0x1CC) < 0) {
        *(s32 *)(p + 0x1D0) = 0;
        *(s32 *)(p + 0x1CC) = 7;
    }
}
