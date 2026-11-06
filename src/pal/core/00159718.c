#include "common.h"

extern s32 func_00158A40(s32 command, s32 byte_count, const void *payload);

s32 func_00159718(void)
{
    return func_00158A40(0x4B, 0, 0);
}
