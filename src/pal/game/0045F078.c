/* Reference: OpenRAC/rac1-decomp @ 1d8228cc0c81da7bc2bdc3e77479ee050e0ef434; LinkHudBank / func_001FF7F0 (src/game/ui/hud.c).
 * Independently reconstructed and checked against RAC4 PAL retail. */
#include "common.h"

typedef struct {
    u32 address;
    u32 unknown4;
} HudEntry;

typedef struct {
    u8 unknown0[12];
    u8 *header;
    u8 unknown10[8];
    HudEntry *table2;
    HudEntry *table1;
} HudState;

typedef struct {
    u8 unknown0[0x14];
    s32 limits[0];
} HudLimits1;

typedef struct {
    u8 unknown0[0x34];
    s32 limits[0];
} HudLimits2;

extern HudState D_0023F530;

/* The cross-game reference is RAC1 LinkHudBank, src/game/ui/hud.c.
 * All offsets and both relocation passes are reconstructed from PAL retail. */
void func_0045F078(s32 bank, u32 address)
{
    u32 *banks;
    u32 *slot;
    s32 first;
    s32 limit;
    s32 i;

    banks = (u32 *)(D_0023F530.header + 0x74);
    slot = &banks[bank];
    if (*slot != 0) {
        return;
    }
    address = (address + 15) & 0xFFFFFFF0;
    *slot = address;
    if (bank != 0) {
        first = ((HudLimits1 *)D_0023F530.header)->limits[bank - 1];
    } else {
        first = 0;
    }
    limit = ((HudLimits1 *)D_0023F530.header)->limits[bank];
    for (i = first; i < limit; i++) {
        D_0023F530.table1[i].address &= 0x7FFFFFFF;
        D_0023F530.table1[i].address += address;
    }
    if (bank != 0) {
        first = ((HudLimits2 *)D_0023F530.header)->limits[bank - 1];
    } else {
        first = 0;
    }
    limit = ((HudLimits2 *)D_0023F530.header)->limits[bank];
    for (i = first; i < limit; i++) {
        D_0023F530.table2[i].address &= 0x7FFFFFFF;
        D_0023F530.table2[i].address += address;
    }
}
