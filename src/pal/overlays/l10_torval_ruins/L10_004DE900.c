#include "common.h"
typedef struct Owner {
    u8 unused[0xAC];
    const u8 *state;
} Owner;
s32 func_L10_004DE900(const Owner *owner)
{
    return *(const s16 *)(owner->state + 0x76) == 0;
}
