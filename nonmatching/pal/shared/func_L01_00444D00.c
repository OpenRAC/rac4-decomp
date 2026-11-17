/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 35/152 (19 words differ).
 * Function text: 152 B; native catalogue: 152 B; 13 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_00444D00 nonmatching/pal/shared/func_L01_00444D00.c --diff
 */
#include "common.h"

extern void func_L01_004448B0(void *, s32);
extern void func_L01_00444AE0(void *, s32);

void func_L01_00444D00(u8 *object)
{
    u8 *linked = *(u8 **)(object + 0xAC);
    u8 *state = linked + 0xE4;
    u8 *other = *(u8 **)(linked + 0xE0);
    s32 value = *(s32 *)(state + 0x1B0);

    *(s32 *)(state + 0x1AC) = *(s32 *)(state + 0x348);
    *(s32 *)(state + 0x1BC) = value;
    state[0x559] = 1;
    state[0x575] = 0x53;
    state[0x577] = 0xFF;
    *(s32 *)(state + 0x1A0) = 0;
    *(s32 *)(state + 0x1B0) = 0;
    state[0x574] = 0;
    state[0x576] = 0xFF;
    state[0x578] = 0x7F;
    state[0x579] = 0x7F;
    state[0x57A] = 0x7F;
    state[0x57B] = 0x7F;
    if (*(s32 *)(other + 0x2318) == 1) {
        func_L01_004448B0(object, value);
        return;
    }
    func_L01_00444AE0(object, value);
}
