#include "common.h"

typedef struct {
    u32 unk00;
    s32 value;
    u8 pad08[0x34];
} Record;

extern Record D_00306EC0[];

s32 func_0049BE58(s32 index)
{
    return D_00306EC0[index].value;
}
