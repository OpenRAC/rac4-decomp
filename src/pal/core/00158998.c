#include "common.h"

extern s32 func_001589B8(u32 word0, u32 word1, u32 word2,
                         u32 word3, u32 word4, u32 word5,
                         void (*complete)(s32 result, u64 userdata), u64 userdata);

s32 func_00158998(u32 word0, u32 word1, u32 word2, u32 word3, u32 word4, u32 word5)
{
    return func_001589B8(word0, word1, word2, word3, word4, word5, 0, 0);
}
