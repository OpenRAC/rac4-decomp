#include "common.h"

extern void func_0049B148(s32, s32);
extern void func_0049C290(s32 param, s32 count);
extern void func_0049D280(s32, s32);
extern u8 D_30B9D8[];

/* Reset the block at D_30B9D8: clear the two calls with zero arguments, set the flag byte at +0xC to 1 and the word at +0x8 to 0x1E, then call func_0049B148 with zeros. */
void func_004C5B20(void) {
    u8 *blk;

    blk = D_30B9D8;
    func_0049D280(0, 0);
    func_0049C290(0, 0);
    *(s32 *)(blk + 0x8) = 0x1E;
    blk[0xC] = 1;
    func_0049B148(0, 0);
}
