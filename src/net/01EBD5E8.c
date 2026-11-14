/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 b[8]; } A8;
typedef struct { u16 n; } Str;
typedef struct { char _p0[8]; A8 f8; s32 f10; char _p14[0x70]; Str *f84; } Peer;
typedef struct { u16 type; u16 data[0x207]; } Msg;
typedef struct { u8 b[16]; } Out;
extern void *func_0011A370(void *, const void *, u32);
extern s32 func_01EA7830(s32, A8, s32, Msg *, s32, Out *);
s32 func_01EBD5E8(s32 *h, Peer *p) {
    Msg m;
    Out o;
    s32 r;
    if (p->f84 == 0) {
        return 3;
    }
    m.type = 0x4000;
    func_0011A370(m.data, p->f84, p->f84->n * 2 + 2);
    r = func_01EA7830(*h, p->f8, p->f10, &m, p->f84->n * 2 + 4, &o);
    p->f84->n = 0;
    return r;
}
