#include "common.h"
typedef struct {
    s32 f0, f4;
    void *data;
    char tail[12];
} Item;
typedef struct {
    char pad[0x34];
    Item *items;
    char tail[0x18];
    s32 count, index;
} List;
typedef struct {
    s32 f0, f4;
    s32 flags;
    s32 handle;
    char pad[0x330];
    List list;
    char tail[0x14];
} State;
extern State D_00320178[];
extern s32 D_00221C28;
extern char D_001CE268[];
extern s32 func_00506BB8(void), func_0049A9D8(void *, s32), func_004A2798(s32 *, s32), func_005071B8(s32, u32);
extern void func_0049AA18(s32);
static inline Item *selected(List *l)
{
    if (l->index < 0)
        return 0;
    return l->items + l->index;
}
void func_004D9930(void)
{
    State *p = D_00320178 + func_00506BB8();
    List *l = &p->list;
    if (l->count > 0) {
        Item *item;
        if (p->handle) {
            func_0049AA18(p->handle);
            p->handle = 0;
        }
        item = selected(l);
        p->handle = func_0049A9D8(D_001CE268 + (*(s32 *)item->data) * 8, -1);
        func_005071B8(func_004A2798(&D_00221C28, 4), p->handle);
    }
    p->flags &= ~2;
}
