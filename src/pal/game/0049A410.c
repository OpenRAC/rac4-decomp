#include "common.h"

typedef struct {
    u32 *child;
    void *object;
} Node;
typedef struct {
    s32 index;
    s32 reserved;
    s32 count;
    Node *nodes[0];
} Ring;
extern Ring D_002F3CD0;
extern void func_00163990(void);
extern s32 func_004A3AF0(void *, u32, u32);
s32 D_0021F690 = 0;

void func_0049A410(s32 unused, s32 mode)
{
    s32 index;
    s32 next;
    if (mode == 1) {
        D_0021F690++;
        if (D_0021F690 >= 6) {
            D_0021F690 = 0;
            func_00163990();
        }
        return;
    }
    if (mode == 0) {
        Node *node = D_002F3CD0.nodes[D_002F3CD0.index];
        if (node->child != NULL)
            func_004A3AF0(node->object, node->child[1], 0);
    }
    index = D_002F3CD0.index;
    D_0021F690 = 0;
    next = index + 1;
    next %= 8;
    D_002F3CD0.count--;
    D_002F3CD0.index = next;
}
