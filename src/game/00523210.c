#include "common.h"
/* Pool records occupy 0x20 bytes: 46F948 reads flag+15 and clears0x20. */
typedef struct Node {
    char pad[0x10];
    struct Node *next;
    char tail[0xC];
} Node;
typedef struct {
    char pad[0x24];
    char *table;
    char gap[0x18];
    char *entry;
    f32 position, scale;
    u16 value;
    char gap4E[2];
    Node *nodes;
    u8 index;
} State;
typedef struct {
    char pad[0x2EF0];
    State *state;
} Object;
extern void func_0046F068(Node *);
static inline u32 add(u32 offset, u32 base)
{
    return offset + base;
}
void func_00523210(Object *p, s32 index, s32 frame)
{
    State *state = p->state;
    Node *node = state->nodes;
    while (node) {
        func_0046F068(node);
        node = node->next;
    }
    state->index = index;
    state->nodes = 0;
    {
        char *entry = *(char **)(state->table + (index << 2) + 0x48);
        state->position = (f32)frame;
        state->scale = 1.0f;
        state->entry = entry;
        state->value = *(u16 *)((char *)add(frame << 2, (u32)entry) + 0x20);
    }
}
