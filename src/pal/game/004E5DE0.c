#include "common.h"
extern void func_00159608(s32, s32, s32, s32, s32);
extern void func_00126E20(s32);
extern s32 func_00449B28(s32, s32);
extern void func_004E5B78(s32), func_00453E20(void *, s32, s32), func_0045E6A0(void);
extern u8 D_001D2280[];
extern s32 D_00221F00, D_00221F04, D_00221F0C, D_00221F10, D_00221F14;
extern u32 *D_00221F08;
extern s16 D_00206A18[];
extern u32 D_00172048[];

void func_004E5DE0(u32 offset, u32 bytes, u32 *entry, s32 mode, s32 special)
{
    D_001D2280[0x43] |= 8;
    func_00159608(2, 0, 0, 0, 0);
    func_00126E20(0);
    D_00221F00 = offset;
    D_00221F04 = bytes;
    D_00221F08 = entry;
    D_00221F0C = mode;
    D_00221F10 = special;
    func_00449B28(4, 1);
    D_00221F14 = D_00206A18[0];
    func_004E5B78(1);
    func_00453E20(D_00172048, 0x400, 0x18);
    func_0045E6A0();
}
