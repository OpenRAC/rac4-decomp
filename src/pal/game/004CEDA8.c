#include "common.h"
typedef struct {
    const char *label;
    s32 icon;
} Data;
typedef struct {
    u8 prefix[8];
    Data *data;
    u8 suffix[12];
} Item;
typedef struct {
    u8 prefix[0x34];
    Item *items;
    u8 gap[0x18];
    s32 count, index;
} List;
typedef struct {
    s32 a, b, flags;
    s32 handle;
    u8 gap[0x200];
    List list;
} State;
extern u8 D_0030ECC0[], D_001CDDC8[];
extern s32 D_00221A40;
extern s32 func_00506BB8(void), func_0049A9D8(const void *, s32), func_004A2798(s32 *, s32), func_005071B8(s32, s32);
extern void func_0049AA18(s32);
static inline s32 count(List *list)
{
    return list->count;
}
static inline Item *selected(List *list)
{
    if (list->index < 0)
        return NULL;
    return (Item *)((u32)list->items + (u32)list->index * 24);
}
void func_004CEDA8(void)
{
    State *state = (State *)((u32)D_0030ECC0 + (u32)func_00506BB8() * 0x280);
    if (count(&state->list) > 0) {
        Data *data = selected(&state->list)->data;
        const void *resource = (void *)((u32)D_001CDDC8 + ((u32)data->icon << 3));
        if (state->handle) {
            func_0049AA18(state->handle);
            state->handle = 0;
        }
        state->handle = func_0049A9D8(resource, -1);
        func_005071B8(func_004A2798(&D_00221A40, 3), state->handle);
    }
    state->flags &= ~2;
}
