/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern s32 func_L00_00528050(void *arg0, s32 arg1, char *arg2, s32 arg3, char *arg4);

/* writes two labelled fields and returns their total length */
s32 func_L00_00527FB8(void *arg0, s32 arg1, s32 arg2, char *arg3, s32 arg4, char *arg5) {
    s32 n;
    s32 m;

    n = func_L00_00528050(arg0, arg1, arg3, arg4, arg5);
    if (n != 0) {
        m = func_L00_00528050(arg0, arg2, arg3, arg4, arg5 + n);
        if (m != 0) {
            return n + m;
        }
    }
    return 0;
}
