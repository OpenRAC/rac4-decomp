/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u32 f0; char _p4[0x88]; u16 *f8C; } Chan;
typedef struct { u16 f0; u16 f2; u32 f4; } Msg;
typedef struct { s32 f0; } Sess;
extern Chan *func_01ED2458(Sess *, s32);
extern void func_01ED2678(Sess *, u16, s32);
s32 func_01ED1718(Sess *s, s32 a, s32 b, Msg *m) {
    Chan *c;
    if (s == 0) {
        return -1;
    }
    if (m == 0) {
        return -1;
    }
    c = func_01ED2458(s, a);
    if (c == 0) {
        return -1;
    }
    if (m->f4 >= c->f0) {
        return -1;
    }
    c->f8C[m->f4] = m->f0;
    func_01ED2678(s, m->f0, 1);
    return 8;
}
