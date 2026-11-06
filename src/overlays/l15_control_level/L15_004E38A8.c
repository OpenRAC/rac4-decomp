#include "common.h"
s32 func_L15_004E38A8(const u8 *owner)
{
    const u8 *state = *(const u8 *const *)(owner + 0xAC);
    if (owner[0x69] == 3) {
        const u8 *parent = *(const u8 *const *)(state + 0x108);
        return parent[0x55] & 2;
    }
    return owner[0x55] & 2;
}
