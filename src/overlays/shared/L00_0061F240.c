#include "common.h"

typedef struct {
    u32 unk00;
    s32 value;
    u8 pad08[0x4C];
} Record;

extern Record D_002F90B8[];

s32 func_L00_0061F240(s32 index)
{
    return D_002F90B8[index].value;
}
