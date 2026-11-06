#include "common.h"

typedef struct { u8 pad00[12]; s32 value; u8 pad10[68]; } Entry;
extern Entry D_002F33B8[];

/* Read entries 0..3, return zero for 4, and -1 for every other index. */
s32 func_00498468(u32 index)
{
    if (index < 4)
        goto found;
    return index == 4 ? 0 : -1;
found:
    return D_002F33B8[index].value;
}
