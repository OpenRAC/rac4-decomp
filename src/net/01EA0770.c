/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 b[8]; } A8;
typedef struct { char _p0[0x84]; u16 f84; } Iface;
typedef struct { char _p0[0x1C]; s32 (*f1C)(s32, u16 *); } NetOps;
typedef struct { char _p0[0x468]; s32 f468; char _p46C[8]; s32 f474; } Peer;
typedef struct { s32 f0; A8 f4; char _pC[8]; u32 f14; } Info_18;
extern s32 func_01EA02C8(A8 *);
extern NetOps *D_00167F3C;
extern Iface *D_00167F40;
s32 func_01EA0770(Info_18 *o, Peer *x) {
    u16 port;
    s32 r;
    func_01EA02C8(&o->f4);
    o->f0 = 4;
    o->f14 = 0;
    if (D_00167F3C != 0) {
        o->f14 = D_00167F40->f84;
    }
    if (x != 0) {
        if (x->f468 == 2) {
            port = 0;
            r = D_00167F3C->f1C(x->f474, &port);
            if (r != 0) {
                return r;
            }
            o->f0 = 6;
            o->f14 |= port << 16;
        } else {
            o->f14 = 0;
        }
    }
    return 0;
}
