/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 b[8]; } A8;
typedef struct { A8 addr; s32 port; } Peer_c;
typedef struct { s32 h; s32 f4; s32 f8; } Ent_c;
typedef struct { s32 f0; Ent_c ents[32]; } Ctx_184;
extern s32 func_01EBE1B8(s32, s32, A8 *, s32 *);
extern s32 func_01EA8BD0(A8, A8);
s32 func_01EBB980(Ctx_184 *c, Peer_c *want, s32 *out) {
    A8 a;
    s32 port;
    u32 i;
    s32 r;
    for (i = 0; i < 32; i++) {
        if (c->ents[i].h != 0) {
            r = func_01EBE1B8(c->f0, c->ents[i].h, &a, &port);
            if (r != 0) {
                return r;
            }
            if (func_01EA8BD0(a, want->addr) != 0 && port == want->port) {
                *out = c->ents[i].h;
                c->ents[i].h = 0;
                return 0;
            }
        }
    }
    return 0;
}
