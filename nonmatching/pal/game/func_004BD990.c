/* Not matching yet: PAL WIP; container/result-bypass/delay residue. Not part of the build.
 * Primary main .text 0x004BD990, native 176 bytes. Preferred h03 actual text is 180 bytes;
 * three default PAL trials produced three texts (172/184/180). Smallest is not preferred.
 * Retained h03 input and actual CompiledSource are byte-equal; body is unchanged here.
 * Selected-index/fallback/two-scale graph recovered. Conditional node reads, first
 * selected result with continued scan and fresh iteration count remain as reviewed.
 * Native NULL-entry hazard is deliberately retained: entry+8 is dereferenced even
 * after a negative fallback selects NULL. No safety/domain/nonalias/extent promise.
 * Getter may return -1; state, selected scale and increment use defined low32 word roles.
 * Current canonical s32 func_00505B20(void) binds actual PAL 0x00506BB8; byte carrier
 * D_0030A6F0 binds primary MAIN.bss 0x0030A6F0. Real R26 and HI16/LO16 pair are valid.
 * No GPREL or allocated data. Per-program/source-bound 16-image proof is not newly certified.
 * Residual: container hoisted before loop, BNEL/result-bypass/count placement rather
 * than native BNE/container delay, base/register and branch/restore scheduling.
 * Existing helper/caller/storage evidence is scoped; no whole C-link or runtime acceptance.
 * Historical automatic attempt5 source/run/final object remains UNKNOWN.
 * Reproduce without extra flags:
 * python3 tools/check_func.py --version pal func_004BD990 nonmatching/pal/game/func_004BD990.c --diff
 */
#include "common.h"

extern u8 D_0030A6F0[];
extern s32 func_00505B20(void);

s32 func_004BD990(void)
{
    u8 *state;
    u8 *container;
    u8 *entry;
    u8 *node;
    s32 index;
    s32 selected;
    s32 result;

    state = (u8 *)((u32)D_0030A6F0 + (u32)func_00505B20() * 0x534U);
    result = -1;
    index = 0;
    if (*(s32 *)(state + 0x518) > 0) {
        do {
            container = state + 0x4C8;
            if (result == -1) {
                selected = index;
                if (selected < 0) {
                    selected = *(s32 *)(container + 0x54);
                    if (selected < 0) {
                        entry = NULL;
                        goto entry_ready;
                    }
                }
                entry = (u8 *)((u32)*(u8 **)(container + 0x34) +
                               (u32)selected * 0x18U);
entry_ready:
                node = *(u8 **)(entry + 8);
                if (*(s32 *)(node + 8) != 1) {
                    result = *(u8 *)(node + 2) != 0 ? index : result;
                }
            }
            index = (s32)((u32)index + 1U);
        } while (index < *(s32 *)(container + 0x50));
    }
    return result;
}
