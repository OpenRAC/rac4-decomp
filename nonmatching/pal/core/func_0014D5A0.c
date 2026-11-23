/* Not matching yet: PAL WIP; main core.text 0x0014D5A0, 404B. Not part of the build. */
/*
 * Integer selection/deadband read graph repaired. Predicate MOVZ/MOVN encoding, cap/4000 constant
 * placement, FP registers and positive/negative continuation scheduling remain different; 404B is
 * nonexact.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: f6d356b6f1bc25d7cd8b717c1c85155a946e5375c4827bf55d69c6c4a560d669
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0014D5A0 nonmatching/pal/core/func_0014D5A0.c --diff
 */
#include "common.h"

f32 func_00136788(f32, f32);

s16 func_0014D5A0(void *object, s16 requested)
{
    s32 selected = 176;
    f32 selected_float;
    f32 current;
    f32 delta;
    f32 excess;
    f32 value;
    f32 adjusted;

    if (requested > 0) {
        selected = requested;
    }
    selected_float = (f32) selected;
    current = *(f32 *) ((s8 *) object + 4);
    delta = selected_float - current;

    if ((delta <= 16.0f) && (-16.0f <= delta)) {
        excess = 0.0f;
    } else if (delta < -16.0f) {
        excess = delta + 16.0f;
    } else {
        excess = delta - 16.0f;
    }

    if (excess == 0.0f) {
        return 0;
    }

    if (excess < 0.0f) {
        value = -func_00136788(10.0f, -excess * 0.01764706f);
        if (value < -1.0592537f) {
            value = -1.0592537f;
        }
        adjusted = value + 1.0f;
    } else {
        value = func_00136788(10.0f, excess * 0.01764706f);
        if (value > 1.0592537f) {
            value = 1.0592537f;
        }
        adjusted = value - 1.0f;
    }
    return (s16) (s32) (adjusted * 4000.0f);
}
