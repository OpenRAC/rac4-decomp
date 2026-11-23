/* Not matching yet: PAL WIP; level_00 .text 0x005DF8F0, 140B. Not part of the build. */
/*
 * Nativeendword arrives inv1 then DADDUa2,v1 at+28 aftertimecapture; actualendword directly
 * livesa1 withnocopy. Native latched livesa1, actuala2. NativefirstLBU+30/NOP+34,
 * actualfirstLBU+2C withnoNOP. Thus two missinginstructions (endcopy/firstloadNOP), registerswap,
 * and corresponding relativebranch distances. Nativebody+38 and actual+30 onwards have same
 * operations with these end/latch allocation roles.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 504f379c83bd597ec7a05b246684f4432cea02d9e33cf5ae556d3193d185072c
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_005DF8F0 nonmatching/pal/shared/func_L00_005DF8F0.c --diff
 */
#include "common.h"

extern s32 D_0021DE40;
extern s32 D_00222550_pal_count;
extern u8 *D_0022256C;
extern u8 *D_00222570;

void func_L00_005DF8F0(void)
{
    u8 *cursor = D_0022256C;
    s32 latched = 0;
    u8 *end = D_00222570;

    D_00222550_pal_count = 0;
    if ((u32)cursor < (u32)end) {
        u32 now = (u32)D_0021DE40;
        do {
            u8 kind = cursor[0x20];
            if ((kind >= 0xFEu && now >= *(u32 *)(cursor + 0xA0)) || latched != 0) {
                D_00222550_pal_count = (s32)((u32)D_00222550_pal_count + 1u);
                if (cursor[0x20] == 0xFFu) {
                    latched = 1;
                }
            }
            cursor += 0x100;
        } while ((u32)cursor < (u32)end);
    }
}
