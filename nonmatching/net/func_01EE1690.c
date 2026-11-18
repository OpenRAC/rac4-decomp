/* Not matching yet: BYTES 20/200 (tools/try_func.py func_01EE1690 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Node { struct Node *f0; struct Node *f4; char _p8[0xC]; u32 f14; char _p18[0x50]; s32 f68; } Node;
extern Node *D_0016AC18;
extern Node *D_0016AC1C;

Node *func_01EE1690(Node *o) {
    Node *n;
    Node *p;

    if (o == 0) {
        return 0;
    }
    if (o == D_0016AC1C) {
        n = o->f4;
        D_0016AC1C = n;
        if (n == o) {
            D_0016AC1C = 0;
        }
        p = o;
    } else if (o == D_0016AC18) {
        n = o->f4;
        D_0016AC18 = n;
        if (n == o) {
            D_0016AC18 = 0;
        }
        p = o;
    } else {
        p = o;
        while (1) {
            if (p == 0) {
                break;
            }
            if (p == D_0016AC18 || p == D_0016AC1C) {
                break;
            }
            p = p->f4;
            if (p == o) {
                p = 0;
                break;
            }
        }
    }
    if (p == 0) {
        return 0;
    }
    o->f4->f0 = o->f0;
    o->f0->f4 = o->f4;
    return o;
}
