#include "common.h"

extern void func_0050ED88(void *);

// Stores arg1 in the field at 0xC of the structure at 0x40; sets the flag at 0x44 and calls func_0050ED88 when the value changes and bit 0x20 is set.
void func_0050EDC8(u8 *arg0, s32 arg1) {
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x40);
    if (*(s32 *)(temp + 0xC) != arg1) {
        arg0[0x44] = 1;
        if (*(u16 *)(temp + 0x40) & 0x20) {
            func_0050ED88(arg0);
        }
    }
    *(s32 *)(*(u8 **)(arg0 + 0x40) + 0xC) = arg1;
}
