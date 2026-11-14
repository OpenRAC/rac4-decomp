/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Node { char _p0[0x4C]; struct Node *f4C; } Node;
typedef struct { char _p0[0x12C]; Node *f12C; } Ctx;
extern Ctx *D_00167F38;
extern Node *func_01EC98E8(s32);
s32 func_01EC9858(s32 id) {
    Node *o = func_01EC98E8(id);
    Ctx *c;
    Node *p;
    if (o != 0) {
        c = D_00167F38;
        if (o == c->f12C) {
            c->f12C = o->f4C;
        } else {
            p = c->f12C;
            while (p != 0) {
                if (o == p->f4C) {
                    p->f4C = o->f4C;
                    break;
                }
                p = p->f4C;
            }
        }
        o->f4C = 0;
    }
    return 0;
}
