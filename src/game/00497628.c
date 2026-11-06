#include "common.h"

typedef s32 (*Type1)(s32);

/* Advance to the next permitted index, reporting whether it changed. */
s32 func_00497628(s32 *current, s32 count, Type1 predicate)
{
    s32 index = *current;
    index++;
    index %= count;
    if (predicate) {
        while (index != *current) {
            if (predicate(index))
                break;
            index++;
            index %= count;
        }
    }
    if (index != *current) {
        *current = index;
        return 1;
    }
    return 0;
}
