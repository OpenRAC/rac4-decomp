#include "common.h"
#include "pal/record_003D6498.h"

void func_00439550(s32 unused, const u8 *state)
{
    s32 index = 0;
    s32 remaining;
    PalRecord003D6498 *entry;

    if (state != NULL) {
        u8 slot = state[0x558];
        if (slot == 0xFF)
            return;
        index = state[0x54C] * 4 + slot;
    }

    remaining = 7;
    entry = D_003D6498[index];
    do {
        entry->f1 = 0;
        --remaining;
        entry->f6 = 0;
        entry->f0 = 0;
        ++entry;
    } while (remaining >= 0);
}
