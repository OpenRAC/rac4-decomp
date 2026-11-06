#include "common.h"

typedef struct {
    u32 unk00;
    s32 value;
    u8 pad08[0x34];
} Record;

extern Record D_00306DC0[];

s32 func_0049B120(s32 index)
{
    return D_00306DC0[index].value;
}
