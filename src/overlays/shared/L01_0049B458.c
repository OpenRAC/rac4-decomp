/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern u8 *D_00221CC0;

void func_L01_0049B458(void) {
    u8 *p = D_00221CC0;
    if (p == 0) return;
    if (*(s16 *)(p + 0xBC) != 0x26C2) {
        D_00221CC0 = 0;
        return;
    }
    {
        s32 *q = *(s32 **)(p + 0xAC);
        if (q != 0) q[2]++;
    }
}
