/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x10]; u32 f10; u32 f14; char _p18[0x60]; u8 f78; } Chan;
typedef struct { char _p0[0x474]; s32 f474; } Sess;
typedef struct { char _p0[0x64]; s32 (*f64)(s32, u32); } Api;
extern Api *D_00167F3C;
extern Chan *func_01ED2458(Sess *, u32);
extern s32 func_01EA42D8(s32);
extern u16 *func_01ED0BE0(Sess *, u8);
s32 func_01ECFD78(Sess *s, u32 v) {
    s32 r = 0;
    Chan *c = func_01ED2458(s, v);
    u16 *p;
    if (c == 0) {
        return 0x17;
    }
    if (v >= c->f10) {
        return 0x17;
    }
    if (v != c->f78) {
        return 0x17;
    }
    if ((u8)v != 0xFF) {
        r = func_01EA42D8(D_00167F3C->f64(s->f474, v));
        if (r == 0) {
            p = func_01ED0BE0(s, c->f78);
            if (p != 0) {
                u32 i;
                for (i = r; i < c->f14; i++) {
                    p[i] = -2;
                }
            }
            c->f78 = -1;
        }
    }
    return r;
}
