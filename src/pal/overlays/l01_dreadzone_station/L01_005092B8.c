#include "common.h"
f32 func_L01_005092B8(const u8 *object)
{
    if (object[0x69] == 1)
        return 0.0f;
    if (object[0x69] == 2)
        return 0.25f;
    if (object[0x69] == 3)
        return 0.5f;
    if (object[0x69] == 4)
        return 0.75f;
    return 0.0f;
}
