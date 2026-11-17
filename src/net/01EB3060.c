/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Node { struct Node *f0, *f4; } Node;
typedef struct { char _p0[8]; Node *f8, *fC; } List;
void func_01EB3060(List *l, Node *n) {
    if (l == 0 || n == 0) {
        return;
    }
    if (n->f4 != 0) {
        n->f4->f0 = n->f0;
    } else {
        l->fC = n->f0;
    }
    if (n->f0 != 0) {
        n->f0->f4 = n->f4;
    } else {
        l->f8 = n->f4;
    }
}
