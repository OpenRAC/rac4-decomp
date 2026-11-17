/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01E9C258(void *, s32, s32 *);
extern s32 func_01E9C240(void *, s32, s32 *, s32);
extern s32 func_01E9C338(void *, s32, s32, s32);
s32 func_01E9C358(void *a, s32 b, s32 *id, s32 d, s32 e) {
    s32 r;
    if (func_01E9C258(a, b, id) < 0) {
        r = func_01E9C240(a, b, id, d);
        if (r < 0) {
            return r;
        }
    }
    r = func_01E9C338(a, b, *id, e);
    if (r < 0) {
        return r;
    }
    return 0;
}
