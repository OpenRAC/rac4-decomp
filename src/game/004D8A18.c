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
extern s32 D_00221B28;
extern char D_001CE1E8[];
extern s32 func_00505B20(void), func_00499CA0(void *, s32), func_004A1A60(s32 *, s32), func_00506120(s32, u32);
extern void func_00499CE0(s32);
static inline Item *selected(List *l)
{
    if (l->index < 0)
        return 0;
    return l->items + l->index;
}
void func_004D8A18(void)
{
    State *p = D_00320178 + func_00505B20();
    List *l = &p->list;
    if (l->count > 0) {
        Item *item;
        if (p->handle) {
            func_00499CE0(p->handle);
            p->handle = 0;
        }
        item = selected(l);
        p->handle = func_00499CA0(D_001CE1E8 + (*(s32 *)item->data) * 8, -1);
        func_00506120(func_004A1A60(&D_00221B28, 4), p->handle);
    }
    p->flags &= ~2;
}
