/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u32 f0, f4, f8, fC; } Ring;
s32 func_01EA7278(Ring *r, u32 *out) {
    if (r == 0) {
        return 2;
    }
    if (out == 0) {
        return 2;
    }
    if (r->fC == r->f8) {
        *out = 0;
    } else if (r->f4 >= r->f0) {
        *out = r->f8 - r->f4;
    } else {
        *out = r->f0 - r->f4;
    }
    return 0;
}
