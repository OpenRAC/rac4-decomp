/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EAB5B8(void *);
extern s32 func_01EAB500(void *, void *);
s32 func_01EAB228(void *arg0) {
    s32 buf[4];
    s32 r;
    if (arg0 == NULL) {
        return 2;
    }
    r = func_01EAB5B8(buf);
    if (r != 0) {
        return r;
    }
    return func_01EAB500(buf, arg0);
}
