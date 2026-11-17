/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01E9BDE0(void *, s32, s32 *, s32);
extern s32 func_01E9BE70(void *, s32, s32, s32, s32 *, s32);
s32 func_01E9C258(void *a, s32 b, s32 *out) {
    s32 ids[256];
    s32 info[4];
    s32 n;
    s32 i;
    n = func_01E9BDE0(a, b, ids, 256);
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return -2;
    }
    for (i = 0; i < n; i++) {
        if (func_01E9BE70(a, b, ids[i], 8, info, 4) < 0) {
            return -1;
        }
        if (info[0] & 2) {
            break;
        }
    }
    if (i == n) {
        return -2;
    }
    *out = ids[i];
    return 0;
}
