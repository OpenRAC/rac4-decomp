#include "common.h"

extern void func_L00_0066CCE8(void *, s32);

/* Sets the object's mode, updating its child's flags and selection mask. */
void func_L01_004A3100(u8 *a0, u32 mode) {
    u8 *st = *(u8 **)(a0 + 0xAC);

    if (mode < 5) {
        *(s16 *)(a0 + 0x74) = 1 << mode;
        *(u16 *)(*(u8 **)(st + 0x6D0) + 0x34) |= 0x41;
        *(u16 *)(*(u8 **)(st + 0x6D0) + 0x34) &= 0xEFFF;
        *(s32 *)(*(u8 **)(st + 0x6D0) + 0x98) = 0;
        func_L00_0066CCE8(*(u8 **)(st + 0x6D0), 1);
    } else if (mode - 5 < 3) {
        *(u16 *)(*(u8 **)(st + 0x6D0) + 0x34) &= 0xFFFE;
        *(u8 *)(*(u8 **)(st + 0x6D0) + 0x31) = 1;
        *(s16 *)(a0 + 0x74) = 0;
        *(s16 *)(*(u8 **)(st + 0x6D0) + 0x74) = 1 << (mode - 5);
    }
    st[0x683] = mode;
}
