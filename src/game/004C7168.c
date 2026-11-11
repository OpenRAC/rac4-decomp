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
extern s32 func_00505B20(void);
extern void func_004A1358(List *);
extern void func_004A1310(List *);
extern void func_00497980(s32);
void func_004C7168(s32 direction)
{
    s32 index = func_00505B20();
    State *state = D_0030B9D8 + index;
    List *list = &state->list;
    if (list->count >= 2) {
        if (direction)
            func_004A1358(list);
        else
            func_004A1310(list);
        if (state->list.count >= 2)
            func_00497980(10);
        else
            func_00497980(4);
        D_0030B9D8[index].flags |= 3;
    }
}
