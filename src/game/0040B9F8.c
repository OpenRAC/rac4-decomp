/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_0040B948(s32, u16 *);
s32 func_0040B9F8(s32 a0, u16 *a1) {
    u16 t;
    s32 r = func_0040B948(a0, &t);
    if (r != 0) {
        return r;
    }
    return t == *a1 ? 0 : 0x801;
}
