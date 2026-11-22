#include "common.h"

typedef struct Node {
    s32 f0;
    u8 pad4[4];
    s32 f8;
    u8 padC[0x10];
    s32 f1C;
    u8 pad20[0x18];
    struct Node *prev;
    struct Node *next;
} Node;

extern struct { Node *head; } D_00223180;
extern Node *D_00223184;

Node *func_L00_006F69E0(Node *arg0) {
    Node *n = arg0;
    Node *next = n->next;

    if (n->f0 != 0) {
        n->f0 = 0;
    }
    n->f1C = 0;
    n->f8 = 0;
    if (n->prev != 0) {
        n->prev->next = n->next;
    }
    if (n->next != 0) {
        n->next->prev = n->prev;
    }
    if (D_00223184 == n) {
        D_00223184 = n->next;
    }
    D_00223180.head->prev = n;
    n->next = D_00223180.head;
    n->prev = 0;
    D_00223180.head = n;
    return next;
}
