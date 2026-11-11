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
extern u8 D_0030ECC0[], D_001CDD48[];
extern s32 D_00221940;
extern s32 func_00505B20(void), func_00499CA0(const void *, s32), func_004A1A60(s32 *, s32), func_00506120(s32, s32);
extern void func_00499CE0(s32);
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
void func_004CDF08(void)
{
    State *state = (State *)((u32)D_0030ECC0 + (u32)func_00505B20() * 0x280);
    if (count(&state->list) > 0) {
        Data *data = selected(&state->list)->data;
        const void *resource = (void *)((u32)D_001CDD48 + ((u32)data->icon << 3));
        if (state->handle) {
            func_00499CE0(state->handle);
            state->handle = 0;
        }
        state->handle = func_00499CA0(resource, -1);
        func_00506120(func_004A1A60(&D_00221940, 3), state->handle);
    }
    state->flags &= ~2;
}
