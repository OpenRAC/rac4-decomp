/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01ECA198(s32 *);
s32 func_01ECA120(s32 *a0, s32 *st) {
    if (st == 0) {
        return 0x17;
    }
    st[1] = 0x1E;
    st[0] = 1;
    if (a0 == 0) {
        st[1] = 0x17;
        return 0x17;
    }
    if (*a0 == 0) {
        st[1] = 0x26;
        return 0x26;
    }
    return st[1] = func_01ECA198(a0);
}
