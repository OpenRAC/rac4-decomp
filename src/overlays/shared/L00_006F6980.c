#include "common.h"

typedef struct Node {
    u8 pad[0x38];
    struct Node *prev;
    struct Node *next;
} Node;

extern struct { Node *a; Node *b; } D_00223180;
extern Node *D_00223184;

Node *func_L00_006F6980(void) {
    Node *n = D_00223180.a;
    Node *next;

    if (n != 0) {
        next = n->next;
        if (next != 0) {
            D_00223180.a = next;
            next->prev = 0;
            n->prev = 0;
            n->next = D_00223180.b;
            if (D_00223180.b != 0) {
                D_00223180.b->prev = n;
            }
            D_00223184 = n;
            return n;
        }
    }
    return 0;
}
