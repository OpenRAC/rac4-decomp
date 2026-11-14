/* cflags: -G0 */
#include "common.h"

typedef struct Node { char _p0[8]; s32 f8; char _pc[4]; s32 f10, f14; char _p18[0x24]; struct Node *f3C; } Node;
typedef struct { char _p0[8]; s32 f8; char _pc[4]; s32 f10, f14; } Obj;
extern Node *D_00167EEC;
s32 func_01E9D9F8(Obj *o) {
    Node *n = D_00167EEC;
    while (n != 0) {
        if (n->f10 == o->f10) {
            n->f14 = o->f14;
            n->f8 = o->f8;
            n = 0;
        } else {
            n = n->f3C;
        }
    }
    return 0;
}
