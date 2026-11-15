/* Not matched: PAL SCES_532.85.
 * SIZE ours 112 / disc 116 at all 16 physical bodies.
 * Symbolic PAL table and actual format replace the literal-address draft.
 * All table/format HI16-LO16 pairs and formatter calls were checked unmasked.
 * Native daddu v1,v0,zero at +0x38 remains absent; branch allocation and
 * subsequent instruction positions differ. Diagnostic alignment is not a match.
 * Store order and post-call float store remain; original complete types,
 * exhaustive runtime bounds and cross-region data declarations are not asserted.
 * No instruction padding, flag change or emitted data is introduced.
 * Stock masked checks do not certify actual regional relocation targets.
 * Reproduce: python3 tools/check_func.py --version pal func_004AEC70 nonmatching/pal/game/func_004AEC70.c --diff
 */
#include "common.h"

extern s32 D_003092A0[];
extern const char D_0021F7B0[];
extern s32 func_0011D920(char *destination, const char *format, ...);

void func_004AEC70(s32 index, s32 value)
{
    s8 changed;
    u8 *record;

    record = (u8 *)D_003092A0 + index * 0x50;
    if (value != *(s32 *)(record + 0x4C)) {
        *(s32 *)(record + 0x4C) = value;
        changed = value >= 2;
        *(s8 *)(record + 0x3D) = changed;
        if (changed != 0) {
            func_0011D920((char *)(record + 0x48), D_0021F7B0, value);
            *(f32 *)(record + 0x44) = 1.0f;
        }
    }
}
