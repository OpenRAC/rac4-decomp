#include "common.h"

static inline u8 is_active_class(const u8 *object)
{
    if (*(const s16 *)(object + 0xBC) == 0x2038) {
        const u8 *state = *(const u8 *const *)(object + 0xAC);
        return *(const u32 *)(state + 0x320) != 0;
    }
    return 0;
}

s32 func_L01_004EF0D8(const u8 *object)
{
    return !is_active_class(object);
}
