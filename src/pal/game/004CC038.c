#include "common.h"

extern void func_004D31F0(s32);
extern s32 func_004E3138(s32, s32, void *);
extern void func_004CB038(s32, s32);
extern s32 D_0021DFEC;
s32 D_0021FAC8 = -1;

/* Set up the menu transition for the requested selection. */
void func_004CC038(s32 selection)
{
    func_004D31F0(0);
    if (selection == -1) {
        func_004E3138(8, 0, 0);
        func_004CB038(1, 0);
    } else {
        D_0021DFEC = selection;
        func_004E3138(14, 0, 0);
        if (!D_0021FAC8)
            func_004CB038(24, 0);
        else
            func_004CB038(15, 0);
    }
}
