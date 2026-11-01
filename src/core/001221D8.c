#include "common.h"

// Rounds the trailing decimal digit and propagates carry, reporting overflow.
s32 func_001221D8(s8 *arg0, s32 arg1) {
    s8 *p;
    if (arg1 > 0) {
        arg1--;
        p = arg0 + arg1;
        if (*p >= '5') {
            do {
                *p = '0';
                arg1--;
                p--;
            } while (arg1 > 0 && *p == '9');
            arg0 += arg1;
            if (*arg0 == '9') return 0;
            *arg0 = (u8)*arg0 + 1;
        }
    }
    return 1;
}
