#include "common.h"

extern void func_0045E1E0(s32 arg0);
extern void func_0045E1F8();
extern s32 D_23F280[];

/* Sets three words of D_23F280 (offsets 0x14, 0x8, 0xC) to -1 and calls func_0045E1E0(0) when word 0 is nonzero. */
void func_0045DE88(void) {
    if (D_23F280[0] != 0) {
        func_0045E1F8();
        D_23F280[2] = -1;
        D_23F280[3] = -1;
        D_23F280[5] = -1;
        func_0045E1E0(0);
    }
}
