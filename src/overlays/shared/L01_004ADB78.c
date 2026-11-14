#include "common.h"

extern s32 func_L00_005E60A0(s32);
extern void func_L01_005B0B70();
typedef int u128 __attribute__((mode(TI)));

// Starts a state-9 action (variant by func_L00_005E60A0(4)), sets a flag and copies the object position.
void func_L01_004ADB78(u8 *arg0) {
    u8 *linked = *(u8 **)(arg0 + 0xAC);
    u8 *blk = linked + 0x200;
    if (func_L00_005E60A0(4) == 0) {
        func_L01_005B0B70(arg0, 9, 4, 5, -1, 0xFFFF, 0xFFFF, 10, -1);
    } else {
        func_L01_005B0B70(arg0, 9, 4, 2, 7, 0xFFFF, 0xFFFF, 10, -1);
    }
    blk[0x11] = 1;
    *(u128 *)(linked + 0x5D0) = *(u128 *)(arg0 + 0x10);
}
