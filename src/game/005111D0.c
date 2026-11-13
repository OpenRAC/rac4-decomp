#include "common.h"

typedef struct Node Node;

struct Node {
    u32 f0;
    s32 f4;
    u32 f8;
    Node *next;
    Node *prev;
    void **vt;
};

extern u32 D_003367FC[];
extern s32 D_00222124;
extern void func_00511450(void *, s32);

void *func_005111D0(u32 arg0, s32 arg1)
{
    s32 off = (arg0 >> 22) & 0x3C;
    Node **bucket = (Node **)((u8 *)D_003367FC + off);
    Node **list = (Node **)((u8 *)D_003367FC - 0x1C + off);
    Node *node = *bucket;
    Node *next;

    if (node != NULL) {
        next = node->next;
        *bucket = next;
        next->prev = NULL;
        node->prev = NULL;
        node->next = *list;
        if (*list != NULL)
            (*list)->prev = node;
        *list = node;
        node->f8 = 1;
        node->f0 = arg0;
        node->f4 = arg1;
        ((void (*)(Node *))node->vt[2])(node);
        if (D_00222124 != -1 && arg1 == D_00222124)
            func_00511450(node, 1);
        return node;
    }
    return NULL;
}
