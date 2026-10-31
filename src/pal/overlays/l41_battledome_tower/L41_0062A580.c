#include "common.h"

extern u8 D_0036E150[];

/* Return the signed word at the start of the indexed 16-byte entry. */
s64 func_L41_0062A580(s32 index)
{
    return *((s32 *)&D_0036E150 + 4 * index);
}
