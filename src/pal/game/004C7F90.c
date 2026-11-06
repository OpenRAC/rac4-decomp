#include "common.h"

typedef struct {
    u8 prefix[0x50];
    s32 count, index;
} List;
typedef struct {
    u8 prefix[0x10];
    u32 flags;
    u8 gap[0xAA0];
    List list;
    u8 tail[0x24];
} State;
extern State D_0030B9D8[];
extern s32 func_00506BB8(void);
extern void func_004A2090(List *);
extern void func_004A2048(List *);
extern void func_004985F0(s32);
void func_004C7F90(s32 direction)
{
    s32 index = func_00506BB8();
    State *state = D_0030B9D8 + index;
    List *list = &state->list;
    if (list->count >= 2) {
        if (direction)
            func_004A2090(list);
        else
            func_004A2048(list);
        if (state->list.count >= 2)
            func_004985F0(10);
        else
            func_004985F0(4);
        D_0030B9D8[index].flags |= 3;
    }
}
