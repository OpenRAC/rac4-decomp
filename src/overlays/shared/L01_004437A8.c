#include "common.h"

extern void func_L00_006B9DC8();
extern void func_L00_006CBB48(void *, s32, s32, s32);
extern s32 func_L00_00700708();

// Check slot 2 of the owner's table, then scan the following slots and select each one that is set.
void func_L01_004437A8(void *self) {
    u8 *owner = *(u8 **)(*(u8 **)((u8 *)self + 0xAC) + 0xE0);
    s32 i = *(s32 *)(owner + 0x2318) + 1;
    if (!(func_L00_00700708(*(s32 *)(owner + 0x26E4), 2) & 0xFF)) {
        func_L00_006CBB48(owner, 2, 0, -1);
    }
    for (; i < 11; i++) {
        if (func_L00_00700708(*(s32 *)(owner + 0x26E4), i) & 0xFF) {
            *(s32 *)(owner + 0x2674) = i;
            func_L00_006B9DC8(owner, 0);
        }
    }
}
