#include "common.h"

s32 func_00496118(s32 *count, s32 current, s32 step, s32 wrap)
{
    if (wrap != 0) {
        current = (current + step + *count) % *count;
    } else {
        current += step;
        if (step < 0) {
            if (current < 0) {
                current = 0;
            }
        } else {
            s32 last = *count - 1;
            if (last < current) {
                current = last;
            }
        }
    }
    return current;
}
