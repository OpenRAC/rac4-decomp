#include "common.h"

typedef struct Node Node;
struct Node { char _p0[0x28]; Node *next; char _p1[0x90]; s16 type; };
extern s32 D_00222D34;

void *func_L01_004AED78(void) {
    Node *n = (Node *)D_00222D34;
    while (n) {
        if (n->type == 0x20ED) return n;
        n = n->next;
    }
    return 0;
}
