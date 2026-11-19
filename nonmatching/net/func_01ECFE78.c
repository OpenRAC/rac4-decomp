/* Not matching yet: BYTES 23/148 (tools/try_func.py func_01ECFE78 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G8 */
#include "common.h"

typedef struct { char _p0[0x474]; s32 f474; } Sess;
typedef struct { void *f0; u32 f4; s32 f8; } Out;
typedef struct { char _p0[0x70]; s32 (*f70)(s32, u32, s32 *); } Api;
extern Api *D_00167F3C;
extern s32 func_01EA42D8(s32);
extern void *func_01ED2458(Sess *, u32);

s32 func_01ECFE78(Sess *s, u32 v, Out *o) {
    s32 r = 0x17;
    s32 sp0;

    sp0 = 0;
    if (o == 0) {
        return r;
    }
    o->f0 = s;
    o->f4 = v;
    o->f8 = 0;
    if (s == 0) {
        return r;
    }
    if (func_01ED2458(s, v) == 0) {
        return 0x17;
    }
    r = func_01EA42D8(D_00167F3C->f70(s->f474, v & 0xFF, &sp0));
    o->f8 = sp0;
    return r;
}
