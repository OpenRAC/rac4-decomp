/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_0047F768(s32 arg0, s32 arg1);
extern void func_004593D8(s32 arg0, s32 arg1, s32 arg2);
extern u8 D_237240[];
extern u32 D_221410;
extern s32 D_002213F4;

// Clears bit 0x80 of the u16 at 0x34 in each 0x100-byte record from D_002213F4 up to D_221410, after two setup calls.
void func_004DCC38(void) {
    u8 *p;

    func_0047F768(0, 0);
    p = D_237240;
    func_004593D8(*(s32 *)(p + 0x25C), *(s32 *)(p + 0x260), *(s32 *)(p + 0x264));
    p = (u8 *)D_002213F4;
    while ((u32)p < D_221410) {
        *(u16 *)(p + 0x34) &= 0xFF7F;
        p += 0x100;
    }
}
