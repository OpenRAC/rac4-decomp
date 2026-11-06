#include "common.h"

typedef struct {
    u8 pad00[0x10];
    s32 value;
    u8 pad14[0x40];
} Entry;

extern Entry D_002F33B8[];

s32 func_004984A0(u32 index)
{
    if (index < 4) {
        return D_002F33B8[index].value;
    }
    return -1;
}
