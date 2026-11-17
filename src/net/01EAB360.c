/* cflags: @ee296 -O2 -G0 */
#include "common.h"
extern s32 func_01EAB270(void *arg0);
extern s32 func_01EAB2A0(void *arg0, s32 *arg1);

s32 func_01EAB360(u32 arg0) {
    s32 buf[4];
    s32 pos = 0;
    s32 r = func_01EAB270(buf);

    if (r != 0)
        return r;
    while (pos < arg0) {
        r = func_01EAB2A0(buf, &pos);
        if (r != 0)
            return r;
    }
    return 0;
}
