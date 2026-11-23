/* Not matching yet: PAL WIP; main .text 0x00548108, 124B. Not part of the build. */
/*
 * Preferred h02 has correct consumed fullword result, unconditional mode3 halfword reads and
 * native read order; remaining instructions differ in initial pointer/base register allocation,
 * shared SLL1/table base placement, reversed mode branch and late mode0 return, absence of native
 * halfword-base DADDU copy, and pure XORI/address/multiply scheduling. h03 has native size but
 * BEQL/annulled pure-address setup and a late mo
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 4adad827b546f19d939f90b37bb6f4acea610a5b078170bad7129604c529ab1d
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00548108 nonmatching/pal/game/func_00548108.c --diff
 */
#include "common.h"
#include "pal/mask_state.h"

typedef struct {
    u8 pad0[0x68];
    s32 f68;
} Type2;
extern Type2 D_00354630[];

s32 func_00548108(s32 index)
{
    u8 mode = D_0021E070[0x1A9];
    u8 *base = (u8 *)D_00354630;
    s32 twice = (s32)((u32)index << 1);
    u8 byte;
    s32 scaled;
    s32 difference;
    s32 converted;

    if (mode == 0) {
        return *(s16 *)(base + twice + 0x56C);
    }
    byte = *(u8 *)(base + index + 0x4B8);
    scaled = byte * 10;
    difference = *(s16 *)(base + twice + 0x418) -
                 *(s16 *)(base + twice + 0x440);
    converted = (s32)*(f32 *)(base + (s32)((u32)index << 2) + 0x4CC);
    if (mode == 3) {
        difference = 0;
    }
    return (s32)((u32)difference + (u32)scaled + (u32)converted);
}
