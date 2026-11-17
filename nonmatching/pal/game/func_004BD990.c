/* Not matched: PAL SCES_532.85.
 * BYTES 50/176 (18 words differ) after actual relocations at all 16 bodies.
 * Reuses the existing table symbol and producer-supported entry/node pointers;
 * per-program helper and BSS bindings were checked against reset and reader.
 * Result/base registers, container computation and fallback/loop scheduling
 * still differ. Original complete types and exhaustive runtime ranges are open.
 * Generic signed fallback, native null hazards and continued scan are retained.
 * Search scores are heuristics; positional equality is not correctness confidence.
 * Stock checks mask relocated fields; they do not certify regional linkage.
 * Reproduce: python3 tools/check_func.py --version pal func_004BD990 nonmatching/pal/game/func_004BD990.c --diff
 */
#include "common.h"

extern u8 D_0030A6F0[];
extern s32 func_00506BB8(void);

/* Find the first eligible record, preserving the native continued scan. */
s32 func_004BD990(void)
{
    s32 fallback;
    s32 index;
    s32 result;
    s32 offset;
    u8 *container;
    u8 *state;
    u8 *node;
    u8 *entry;

    state = D_0030A6F0 + func_00506BB8() * 0x534;
    result = -1;
    index = 0;
    if (*(s32 *)(state + 0x518) > 0) {
        do {
            container = state + 0x4C8;
            if (result == -1) {
                if (index < 0) {
                    fallback = *(s32 *)(container + 0x54);
                    offset = fallback * 0x18;
                    if (fallback < 0) {
                        entry = NULL;
                    } else {
                        goto entry_base;
                    }
                } else {
                    offset = index * 0x18;
entry_base:
                    entry = *(u8 **)(container + 0x34) + offset;
                }
                node = *(u8 **)(entry + 8);
                if (*(s32 *)(node + 8) != 1) {
                    result = *(u8 *)(node + 2) != 0 ? index : result;
                }
            }
            index += 1;
        } while (index < *(s32 *)(container + 0x50));
    }
    return result;
}
