/* cflags: -mno-split-addresses */
#include "common.h"

extern u8 *D_00222D14[];
extern void func_L01_0064EA50(u8 *, s32);
extern void func_L01_0064EAC0(s32, s32);

/* Apply arg1 to the two linked objects and the two handles of the object's +0xAC block. */
void func_L01_0047E690(u8 *arg0, s32 arg1) {
    u8 *state = *(u8 **)(arg0 + 0xAC);
    s32 *p = (s32 *)state;
    s32 count = 1;
    s32 *q;
    do {
        s32 index = *p;
        count--;
        if (index != -1) {
            func_L01_0064EA50(D_00222D14[0] + (index << 8), arg1);
        }
        p++;
    } while (count >= 0);

    q = (s32 *)(state + 8);
    for (count = 1; count >= 0; count--) {
        func_L01_0064EAC0(*q++, arg1);
    }
}
