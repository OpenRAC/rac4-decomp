#include "common.h"

extern u8 *D_00221E20;
extern u8 D_003DA5E0[];
extern u8 D_003DA6B0[];
extern void func_00453718(void *, const void *, u32);

void func_004F8DF8(s32 arg0, const void *arg1)
{
    u8 *current;

    func_00453718(D_00221E20, D_003DA5E0, 0x70);
    current = D_00221E20;
    *(s16 *)(current + 0x24) = arg0 >> 8;
    *(const void **)(current + 0x64) = arg1;
    D_00221E20 += 0x70;
    current = D_00221E20;
    *(u32 *)(current + 0x0) = 0x30000003;
    *(u32 *)(current + 0x4) = (u32)D_003DA6B0;
    *(u32 *)(current + 0x8) = 0;
    *(u32 *)(current + 0xC) = 0x50000003;
    D_00221E20 += 0x10;
}
