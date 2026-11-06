#include "common.h"
typedef struct {
    s32 a, b;
    void *data;
    char tail[12];
} Item;
typedef struct {
    char pad[0x34];
    Item *items;
    char gap[0x18];
    s32 count, index;
} List;
typedef struct {
    s32 a, b, flags;
    char pad[0xA8];
    List list;
    char gap[0x14];
    s32 handle;
} State;
extern State D_00321650[];
extern char D_001CE230[];
extern s32 D_00221C68;
extern s32 func_00506BB8(void), func_0049A9D8(void *, s32), func_004A2798(s32 *, s32), func_005071B8(s32, s32);
extern void func_0049AA18(s32);
static inline Item *selected(List *l)
{
    if (l->index < 0)
        return 0;
    return l->items + l->index;
}
void func_004DA960(void)
{
    State *p = D_00321650 + func_00506BB8();
    List *l = &p->list;
    if (l->count > 0) {
        if (p->handle) {
            func_0049AA18(p->handle);
            p->handle = 0;
        }
        p->handle = func_0049A9D8(D_001CE230 + *(s32 *)selected(l)->data * 8, -1);
        func_005071B8(func_004A2798(&D_00221C68, 4), p->handle);
    }
    p->flags &= ~2;
}
