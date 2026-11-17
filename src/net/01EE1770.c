/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Node { struct Node *f0; struct Node *f4; char _p8[0x60]; s32 f68; } Node;
extern Node *D_0016AC18;
extern Node *D_0016AC1C;
extern s32 func_01EE1758(s32 *, s32 *);
Node *func_01EE1770(s32 *key) {
    Node *n = D_0016AC18;
    while (n != 0) {
        if (func_01EE1758(&n->f68, key) == 0) {
            return n;
        }
        n = n->f4;
        if (n == D_0016AC18) {
            break;
        }
    }
    n = D_0016AC1C;
    while (n != 0) {
        if (func_01EE1758(&n->f68, key) == 0) {
            return n;
        }
        n = n->f4;
        if (n == D_0016AC1C) {
            break;
        }
    }
    return 0;
}
