#include "common.h"

extern void func_004E7990(u32 a0, u64 a1, s32 a2);
extern u8 D_239540[];

// Forwards a 64-bit value to func_004E7990 when D_239540 is active and the stored value changed.
void func_0044D668(s32 unused, u64 arg1) {
    if (D_239540[0] == 0) {
        func_004E7990(6, arg1, 0);
        return;
    }
    if (*(u64 *)(D_239540 + 0x40) != arg1) {
        *(u64 *)(D_239540 + 0x40) = arg1;
        func_004E7990(6, arg1, 1);
        *(s32 *)(D_239540 + 0x10) = 0x7C;
    }
}
