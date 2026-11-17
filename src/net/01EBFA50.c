/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u16 f0; u16 f2; } Hdr;
typedef struct { char _p0[0x64]; u16 f64; } Peer;
typedef struct { char _p0[0x7C]; u16 f7C; } Obj;
extern void *func_0011A518(void *, s32, u32);
void func_01EBFA50(Obj *o, Peer *peer, u16 flags, s32 len, Hdr *h) {
    func_0011A518(h, 0, 4);
    h->f0 = (flags & 0xF800) | (len & 0x7FF);
    if (flags & 0x4000) {
        if (peer != 0) {
            h->f2 = peer->f64;
            peer->f64++;
            if (peer->f64 == 0) {
                peer->f64++;
            }
        }
    } else if (flags & 0x2000) {
        h->f2 = o->f7C;
        o->f7C++;
        if (o->f7C == 0) {
            o->f7C++;
        }
    } else {
        h->f2 = 0;
    }
}
