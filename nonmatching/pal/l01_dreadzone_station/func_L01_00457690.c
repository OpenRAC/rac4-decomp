/* Not matching yet: PAL WIP; level_01 .text 0x00457690, 156B. Not part of the build. */
/*
 * Native two value copies and first-LH delay NOP are absent; direct actual register roles and
 * subsequent layout differ. All source-cell bindings retain their dated ownership qualifications.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: cd2759d549c4aad3108d8b322046effe7c9ebb237cba007677c44ccf24647737
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_00457690 nonmatching/pal/l01_dreadzone_station/func_L01_00457690.c --diff
 */
#include "common.h"

extern s32 D_0021DE98;
extern s32 D_0021EC58;
extern u8 *D_00222E14;
extern u8 *D_00222E2C;

s32 func_L01_00457690(s32 key)
{
    s32 mode = D_0021DE98;
    s32 state;
    u8 *record;
    u8 *end;
    u8 *owner;
    s32 result;

    if (mode == 1 || mode == 0x15) {
        state = D_0021EC58;
        record = D_00222E14;
        if (state == 8) {
            end = D_00222E2C;
            for (; (u32)record < (u32)end; record += 0x100) {
                if (*(s16 *)(record + 0xBC) != 0x2120) continue;
                owner = *(u8 **)(record + 0xAC);
                if (*(s32 *)owner != key) continue;
                result = 0;
                if (*(u8 **)(owner + 0x48) != NULL) {
                    result = record[0x20] < 0xE;
                }
                return result;
            }
        }
    }
    return 0;
}
