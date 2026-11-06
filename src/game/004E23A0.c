#include "common.h"
typedef unsigned int u128 __attribute__((mode(TI)));
extern void func_00159128(void);
extern s32 func_00157F98(void);
extern s32 func_00158838(void);
extern void func_004E2568(void);
extern u128 D_001D2250[];
extern u8 D_001D2200[];
void func_004E23A0(void)
{
    s32 remaining;
    u32 row;
    func_00159128();
    func_00157F98();
    func_00158838();
    while (func_00157F98() != 0) {
    }
    for (remaining = 3; remaining >= 0; --remaining) {
        D_001D2250[remaining] = 0;
    }
    row = (u32)D_001D2200;
    remaining = 51;
    *(u32 *)(row + 0x48) = 0;
    do {
        *(u32 *)(row + 0x2C0) = 0;
        *(u8 *)(row + 0x2D0) = 0;
        --remaining;
        row += 0x80;
    } while (remaining >= 0);
    func_004E2568();
}
