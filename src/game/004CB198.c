#include "common.h"

extern void func_004D22E0(s32);
extern s32 func_004E21D8(s32, s32, void *);
extern void func_004CA1D0(s32, s32);
extern s32 D_0021DF64;
s32 D_0021FA28 = -1;

/* Set up the menu transition for the requested selection. */
void func_004CB198(s32 selection)
{
    func_004D22E0(0);
    if (selection == -1) {
        func_004E21D8(8, 0, 0);
        func_004CA1D0(1, 0);
    } else {
        D_0021DF64 = selection;
        func_004E21D8(14, 0, 0);
        if (!D_0021FA28)
            func_004CA1D0(24, 0);
        else
            func_004CA1D0(15, 0);
    }
}
