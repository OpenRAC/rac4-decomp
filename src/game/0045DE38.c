#include "common.h"

/* Calls func_0045E1F8, sets words 2 and 3 of D_23F280 to -1, then calls func_0045E1E0 with 2 or 0 by the byte at offset 0x27. */
extern void func_0045E1E0(s32 arg0);
extern void func_0045E1F8();
extern s32 D_23F280[];

void func_0045DE38(void) {
    func_0045E1F8();
    D_23F280[2] = -1;
    D_23F280[3] = -1;
    if (((u8 *)D_23F280)[0x27] != 0) {
        func_0045E1E0(2);
    } else {
        func_0045E1E0(0);
    }
}
