/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EAB288(void *);
extern s32 func_01EAB420(void *, void *, void *);
s32 func_01EAB610(void *arg0, void *arg1) {
    s32 buf[4];
    s32 r;
    if (arg0 == NULL) {
        return 2;
    }
    if (arg1 == NULL) {
        return 2;
    }
    r = func_01EAB288(buf);
    if (r != 0) {
        return r;
    }
    return func_01EAB420(arg0, buf, arg1);
}
