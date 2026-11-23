/* Not matching yet: PAL WIP; main core.text 0x00162768, 220B. Not part of the build. */
/*
 * Invalid latch GPREL16: physical0x212164-GP0x2259FF=-0x1389B, outside signed16; two real GP uses
 * remain unresolved. Compiler also hoists the required live profile+0x10 reload. Header/type-view
 * and helper/binding limitations remain.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 5cc0fcd59b5c8bb0a20c8acf70c1586a6024f103a13a2d8d6e2d8db355ac97a0
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00162768 nonmatching/pal/core/func_00162768.c --diff
 */
#include "common.h"
#include "pal/profile_001721E0.h"
#include "pal/mask_state.h"

extern s32 D_00212164_pal_latch;
extern s32 func_01E9E918(s32, s32);

void func_00162768(s32 arg0)
{
    u8 *profile = (u8 *)&D_001721E0;
    s32 handle;
    u8 *slots;
    s32 i;
    u8 *slot;
    s32 value;

    handle = *(s32 *)(profile + 8);
    if (handle != 0 || (handle = *(s32 *)(profile + 0xC)) != 0) {
        slots = D_0021E070;
        i = 0;
        if (slots != NULL) {
            if (slots[0x104] != *(s32 *)(profile + 0x10)) {
            next_slot:
                i++;
                slot = slots + i;
                if (i < 10) {
                    if (slot[0x104] == *(s32 *)(profile + 0x10)) {
                        *(s32 *)(profile + 0x2C) = slot[0xFA];
                    } else {
                        goto next_slot;
                    }
                }
            } else {
                *(s32 *)(profile + 0x2C) = slots[0xFA];
            }
            if (arg0 != 0) {
                if (D_00212164_pal_latch != 0) {
                    D_00212164_pal_latch = 0;
                    func_01E9E918(handle, 0);
                }
            } else if (D_00212164_pal_latch == 0) {
                value = (s32)((u32)*(s32 *)(profile + 0x2C) + 1U);
                D_00212164_pal_latch = value;
                func_01E9E918(handle, value);
            }
        }
    }
}
