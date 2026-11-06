#include "common.h"

static inline u8 is_active_class(const u8 *object)
{
    if (*(const s16 *)(object + 0xBC) == 0x2038) {
        const u8 *state = *(const u8 *const *)(object + 0xAC);
        return *(const u32 *)(state + 0x320) != 0;
    }
    return 0;
}

s32 func_L01_004ED138(const u8 *object)
{
    const u8 *state;
    const u8 *child;
    if (is_active_class(object))
        return 0;
    state = *(const u8 *const *)(object + 0xAC);
    if (state[0x355] != 0)
        return 0;
    child = *(const u8 *const *)(state + 0x2F4);
    if (child != NULL && child[0x20] == 3)
        return 0;
    return 1;
}
