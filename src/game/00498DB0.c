#include "common.h"

typedef struct {
    u8 pad00[0x84];
    s32 values[0];
} State;

extern State D_002F3408;

s32 func_00498DB0(s32 index)
{
    return D_002F3408.values[index];
}
