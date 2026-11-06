#include "common.h"
typedef struct Node { char pad[0x30]; void *value; struct Node *self; } Node;
extern char D_003CBCCC[];
static __inline__ int eq(Node *a, Node *b) { return a == b; }
/* Return zero for the accepted node. */
int func_003FD5F8(Node *node) {
    Node *p;
    if (!node) goto error;
    p = node->self;
    if (!eq(p, node)) goto error;
    if (p->value == D_003CBCCC) node = 0;
    else error: node = (Node *)0x204;
    return (int)node;
}
