#include "common.h"

extern void func_00497980(s32 arg0);
extern s8 D_0021F8D9;
s8 D_0021F8DA = 0;

/* Calls func_00497980 with 0xE or 0xC, setting the two flags at D_0021F8D9 and D_0021F8DA to match the branch. */
void func_004BAC90(s32 arg0) {
    if (arg0 != 0) {
        D_0021F8D9 = 1;
        func_00497980(0xE);
        D_0021F8DA = 1;
        return;
    }
    func_00497980(0xC);
    D_0021F8DA = 0;
}
