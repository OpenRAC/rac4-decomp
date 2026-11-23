/* Not matching yet: PAL SCES_532.85, SIZE ours 104 / disc 116. Not part of the build.
 * Retained C78 WIP from the unchanged default PAL pipeline, no extra flags.
 * Unconditional threshold input/FP work and the late conditional owner+A8 read
 * were recovered. The first 60 real-bound bytes equal native; this prefix is
 * diagnostic only. The native pre-DIV NOP is absent and the actual two-return,
 * direct SLT tail differs from native selected 0/1 with a shared return.
 * Existing s32(void*) and signed field roles/defined EE32 word-address arithmetic
 * are retained, without new bounds, extent, nonnull, nonalias or FP-domain promises.
 * Existing D_0021DFEC binds resident MAIN.core.lit 0x0021DFEC by the actual HI/LO
 * pair; no GPREL16 or allocated nontext data. No helper calls or target writes.
 * Getter address-only scalar markers remain inherited source-linkage debt; this
 * is not a complete table/extent/initializer or whole-C-program consistency proof.
 * Exceptional signed conversion/FCSR qualifications remain open as documented;
 * no exact, semantic, whole-link or all-carrier certificate or profile transfer.
 * Input equals actual CompiledSource; the exact input bytes follow this header.
 * Reproduce: python3 tools/check_func.py --version pal func_L01_004B07F0 nonmatching/pal/shared/func_L01_004B07F0.c --diff
 */
#include "common.h"

extern s32 D_0021DFEC;

s32 func_L01_004B07F0(void *originalObject)
{
    s32 index = D_0021DFEC;
    u8 *owner = *(u8 **)((u8 *)originalObject + 0xAC);
    u32 selectedAddress = (u32)owner + ((u32)index << 2) + 0x8CU;
    f32 first = (f32)*(s32 *)(owner + 0xA0);
    f32 second = (f32)*(s32 *)selectedAddress;
    s32 status = *(s32 *)(owner + 0xAC);
    s32 threshold = (s32)(((first * second) / 100.0f) + 0.5f);

    if (status > 0) {
        return 0;
    }
    return *(s32 *)(owner + 0xA8) < threshold;
}
