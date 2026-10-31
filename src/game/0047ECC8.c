#include "common.h"

extern void func_00470090(void *arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4);

// Sets the 0x40 byte at offset 0x23, sets bit 8 of the halfword at 0x36, then calls func_00470090 with a color.
void func_0047ECC8(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x23) = 0x40;
    *(u16 *)((u8 *)arg0 + 0x36) = (u16)(*(u16 *)((u8 *)arg0 + 0x36) | 8);
    func_00470090(arg0, 0xFF707070, 0xF, 0xF, 0);
}
