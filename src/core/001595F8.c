#include "common.h"

extern s32 func_00158C60(s32 command, s32 bytes, const void *payload,
                         void (*complete)(s32 result, u64 userdata), u64 userdata);

s32 func_001595F8(u32 word0, u32 word1, u32 word2, u32 word3, u32 word4)
{
    u32 payload[5];
    payload[0] = word0;
    payload[1] = word1;
    payload[2] = word2;
    payload[3] = word3;
    payload[4] = word4;
    return func_00158C60(0x50, 0x14, payload, 0, 0);
}
