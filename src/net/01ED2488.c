/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x474]; s32 f474; } Sess;
typedef struct { char _p0[0x14]; s32 (*f14)(s32, u16 *); s32 (*f18)(s32, u16 *); } Api;
extern Api *D_00167F3C;
extern s32 func_01EA42D8(s32);
extern s32 func_01ED2A78(Sess *, s32, s32);
s32 func_01ED2488(Sess *s, s32 b) {
    u16 v[2];
    s32 r;
    r = func_01EA42D8(D_00167F3C->f14(s->f474, &v[0]));
    if (r != 0) {
        return r;
    }
    r = func_01EA42D8(D_00167F3C->f18(s->f474, &v[1]));
    if (r != 0) {
        return r;
    }
    if (v[0] != 0xFFFE && v[1] == v[0]) {
        r = func_01ED2A78(s, b, 1);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}
