/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Node { char _p0[0x10]; s32 f10; char _p14[0x18]; s32 f2C; char _p30[0xC]; struct Node *f3C; } Node;
typedef struct { s32 f0, f4; } Obj;
extern Node *D_00167EEC;
s32 func_01E9DCA8(Obj *o) {
    Node *n = D_00167EEC;
    while (n != 0) {
        if (n->f10 == o->f4) {
            n->f2C = 0;
            n = 0;
        } else {
            n = n->f3C;
        }
    }
    return 0;
}
