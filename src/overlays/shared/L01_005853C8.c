#include "common.h"

// Calls each non-null callback with its argument; clears both slots on success, returns 0 if any failed.
s32 func_L01_005853C8(s32 (**funcs)(s32), s32 *args, s32 count) {
    s32 result = 1;

    if (count > 0) {
        s32 *a = args;
        s32 (**f)(s32) = funcs;
        s32 n = count;

        do {
            if (*f != 0) {
                if ((*f)(*a) != 0) {
                    *f = 0;
                    *a = 0;
                } else {
                    result = 0;
                }
            }
            a++;
            f++;
        } while (--n != 0);
    }
    return result;
}
