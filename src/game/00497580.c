#include "common.h"

typedef s32 (*Type1)(s32);

s32 func_00497580(s32 *current, s32 count, Type1 predicate)
{
    s32 index = *current;
    index += count;
    index--;
    index %= count;
    if (predicate) {
        while (index != *current) {
            if (predicate(index))
                break;
            index += count;
            index--;
            index %= count;
        }
    }
    if (index != *current) {
        *current = index;
        return 1;
    }
    return 0;
}
