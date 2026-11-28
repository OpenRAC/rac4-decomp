#include "pal/card_state_001719C8.h"

typedef struct {
    u8 pad00[0x24];
    s32 f24;
    u8 pad28[0xD4 - 0x28];
} StateRecord;

/* Read the selected card result while its state is ready. */
s32 func_L00_005DCE80(s32 *unused)
{
    const PalCardState *state = &D_001719C8[0];

    if (state->f1C4 < 3 && state->f1CC < 0) {
        if (state->f1D4 == 0) {
            const StateRecord *records = (const StateRecord *)state;
            return records[state->selectedRecord].f24;
        }
        return 0;
    }
    return -1;
}
