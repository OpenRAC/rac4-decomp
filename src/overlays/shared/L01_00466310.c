/* cflags: -G0 */
#include "common.h"

extern void func_L00_005BADE8(void *, void *, s32, void *, f32);
extern u8 D_00222B28[];
extern u8 D_003A96F0[];

void func_L01_00466310(u8 *arg0) {
    func_L00_005BADE8(D_00222B28, *(u8 **)(arg0 + 0xAC) + 0x60, 2, D_003A96F0, 1.0f);
}
