/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Node { char _p0[4]; struct Node *f4; u32 f8; } Node;
typedef struct { char _p0[8]; Node *f8; } List;
Node *func_01EB3028(List *l, u32 key) {
    Node *n = 0;
    key &= 0x1FFFFFFF;
    if (l != 0) {
        n = l->f8;
    }
    while (n != 0 && n->f8 != key) {
        n = n->f4;
    }
    return n;
}
