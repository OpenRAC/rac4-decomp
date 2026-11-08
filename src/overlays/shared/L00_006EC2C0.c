#include "common.h"

extern void func_L00_005BCAE0();

// Reset the object: clear its first three words, fill the 0x40-byte block at
// 0xC with 0xCD, then clear and invalidate the fields at 0x4C..0x55.
void func_L00_006EC2C0(u8 *arg0) {
    *(s32 *)(arg0 + 0x8) = 0;
    *(s32 *)(arg0 + 0x4) = 0;
    *(s32 *)(arg0 + 0x0) = 0;
    func_L00_005BCAE0(arg0 + 0xC, 0xCDCDCDCD, 0x40);
    *(s32 *)(arg0 + 0x4C) = 0;
    *(u8 *)(arg0 + 0x54) = 0;
    *(s32 *)(arg0 + 0x50) = -1;
    *(u8 *)(arg0 + 0x55) = 0;
}
