/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct PlayerStats {
    u8 unknown[0x29];
    u8 slots[4];
} PlayerStats;

extern PlayerStats D_00171BC0;

/* Keeps an existing ID or stores it in the first empty slot. */
s32 func_L01_004B0BD8(s32 id)
{
    s32 i;
    s32 empty = -1;

    for (i = 0; i < 4; i++) {
        u8 value = D_00171BC0.slots[i];

        if (value == id)
            return 1;
        if (value == 0) {
            empty = i;
            i = 4;
        }
    }
    if (empty == -1)
        return 0;

    D_00171BC0.slots[empty] = id;
    return 1;
}

/* Tests whether a nonzero ID occupies one of the four slots. */
s32 func_L01_004B0C80(s32 id)
{
    u8 *slot;
    s32 i = 0;
    PlayerStats *stats = &D_00171BC0;

    slot = stats->slots;
    do {
        u8 value = *slot;

        ++i;
        if (value != 0 && value == id)
            return 1;
        ++slot;
    } while (i < 4);
    return 0;
}
