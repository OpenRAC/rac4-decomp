#include "common.h"
s32 func_L00_0074C410(const u8 *owner, u32 key)
{
    s32 index;
    const u32 *entry = (const u32 *)(owner + 0x264);
    for (index = 0; index < 4; index++, entry++) {
        if (*entry == key)
            return 1;
    }
    return 0;
}
