#include "common.h"

extern s32 D_1711A8[];
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_L05_004F3EC8(u8 *);

void func_L05_004F3E38(u8 *arg0)
{
    u8 *link;

    *(u8 *)(arg0 + 0x30) = 0xFF;
    *(u16 *)(arg0 + 0x34) |= 0x100;
    link = *(u8 **)(arg0 + 0xAC);
    *(u16 *)(arg0 + 0x32) = 0xC4;
    *(s32 *)(link + 0x14) = 0;
    *(u8 *)(link + 0x11) = 1;
    func_L05_004F3EC8(arg0);
    if (D_1711A8[0] != *(s32 *)(link + 0xC)) {
        func_L01_00591BD8(arg0, 5, -1);
        return;
    }
    func_L01_00591BD8(arg0, 1, -1);
}
