/* cflags: -ffast-math */
#include "common.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Moves *val towards target (at most 1.0): when it is within 0.006 it snaps, otherwise it moves
// up by 7.17 % of the gap (at least 0.006) or down by 3.48 % of it (at least 0.006). Built with
// -ffast-math, as src/pal/game/00502BB8.c, for retail's min.s/max.s.
void func_L02_004CBE78(f32 *val, f32 target) {
    f32 cur;

    target = MIN(target, 1.0f);
    cur = *val;
    if (cur < target) {
        if (target - cur <= 0.006f) {
            *val = target;
            return;
        }
        *val = cur + MAX((target - cur) * 0.071686104f, 0.006f);
    } else {
        if (cur - target <= 0.006f) {
            *val = target;
            return;
        }
        *val = cur + MIN((target - cur) * 0.034792762f, -0.006f);
    }
}
