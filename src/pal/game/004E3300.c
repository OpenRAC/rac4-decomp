#include "common.h"
typedef unsigned int u128 __attribute__((mode(TI)));
extern void func_00159138(void);
extern s32 func_00157FA8(void);
extern s32 func_00158848(void);
extern void func_004E34C8(void);
extern u128 D_001D22D0[];
extern u8 D_001D2280[];
void func_004E3300(void)
{
    s32 remaining;
    u32 row;
    func_00159138();
    func_00157FA8();
    func_00158848();
    while (func_00157FA8() != 0) {
    }
    for (remaining = 3; remaining >= 0; --remaining) {
        D_001D22D0[remaining] = 0;
    }
    row = (u32)D_001D2280;
    remaining = 51;
    *(u32 *)(row + 0x48) = 0;
    do {
        *(u32 *)(row + 0x2C0) = 0;
        *(u8 *)(row + 0x2D0) = 0;
        --remaining;
        row += 0x80;
    } while (remaining >= 0);
    func_004E34C8();
}
