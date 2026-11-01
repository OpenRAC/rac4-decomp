#include "common.h"

typedef struct {
    u8 pad00[0x84];
    s32 values[0];
} State;

extern State D_002F3508;

s32 func_00499AE8(s32 index)
{
    return D_002F3508.values[index];
}
