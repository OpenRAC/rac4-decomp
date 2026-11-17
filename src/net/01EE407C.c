/* cflags: @ee296 -Os -G0 */
#include "common.h"

typedef struct Node { char _p0[0x10]; struct Node *f10; } Node;
extern void (*D_0016AC6C)(void *);
void func_01EE407C(Node *n) {
    while (n != 0) {
        Node *next = n->f10;
        D_0016AC6C(n);
        n = next;
    }
}
