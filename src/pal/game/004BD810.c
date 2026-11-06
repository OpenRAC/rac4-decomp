#include "common.h"
/* The list has capacity 50 and contains nonnull records at 30AC28+n*16.
 * This scan runs before selection is clamped. Its explicit index starts
 * at zero, so it does not consume the helper's negative-selection path.
 */
typedef struct Data {
    u32 unused;
    s32 id;
    s32 kind;
} Data;
typedef struct Item {
    u8 pad00[8];
    Data *data;
    u8 tail[12];
} Item;
typedef struct List {
    u8 pad00[0x34];
    Item *items;
    u8 pad38[0x18];
    s32 count;
    s32 index;
    u8 tail[0x14];
} List;
typedef struct State {
    u8 pad00[0x4C8];
    List list;
} State;
extern u8 D_0030A6F0[];
/* Retail LUI 0022 + signed displacement F218 is address 0021F218. */
extern s32 D_0021F218;
extern s32 func_00506BB8(void);
static inline s32 count(List *list)
{
    return list->count;
}
static inline Item *item(List *list, s32 index)
{
    if (index < 0) {
        index = list->index;
        if (index < 0) {
            return NULL;
        }
    }
    return (Item *)((u32)list->items + (u32)index * 24);
}
s32 func_004BD810(void)
{
    State *state = (State *)((u32)D_0030A6F0 + (u32)func_00506BB8() * 0x534);
    s32 target = D_0021F218;
    s32 result = -1;
    s32 searching = 1;
    s32 i;
    if (target != -1) {
        for (i = 0; i < count(&state->list); i++) {
            if (searching) {
                Data *data = item(&state->list, i)->data;
                if (data->kind != 1 && data->id == target) {
                    result = i;
                    searching = 0;
                }
            }
        }
    }
    return result;
}
