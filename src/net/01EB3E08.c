/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Node_14 { struct Node_14 *f0; struct Node_14 *next; char _p8[8]; u32 id; } Node_14;
typedef struct { Node_14 *head; } List_4;
extern List_4 *D_0016819C;
extern void func_01EB3CE0(u32, Node_14 *);
void func_01EB3E08(u32 id) {
    Node_14 *n = D_0016819C->head;
    u32 k;
    while (n != 0) {
        k = n->id;
        if ((id == 0xFFFFFFFF && k == id) || (id == 0x80000000 && k == (k & 0x7FFFFFFF) + id)
            || (id == 0 && k == (k & 0x7FFFFFFF))) {
            func_01EB3CE0(k, n);
            n = D_0016819C->head;
        } else {
            n = n->next;
            if (n == D_0016819C->head) {
                n = 0;
            }
        }
    }
}
