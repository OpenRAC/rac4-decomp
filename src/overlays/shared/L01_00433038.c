#include "common.h"

extern void func_L01_00432FC8();
typedef int u128 __attribute__((mode(TI)));

// Calls func_L01_00432FC8 for the two sub-blocks at +0x20 and +0x30 of the linked object when their +0x14 and +0x18 words are set; the first call's 16-byte result is copied to the object's +0x10.
void func_L01_00433038(void *arg0)
{
    u8 *linked = *(u8 **)((u8 *)arg0 + 0xAC);
    s32 a;
    u128 buf;

    a = *(s32 *)(linked + 0x14);
    if (a != 0) {
        func_L01_00432FC8(linked + 0x40, a, linked + 0x20, 0, &buf);
        *(u128 *)((u8 *)arg0 + 0x10) = buf;
    }
    a = *(s32 *)(linked + 0x18);
    if (a != 0) {
        func_L01_00432FC8(linked + 0x40, a, linked + 0x30, 1, &buf);
    }
}
