#include "common.h"
#include "pal/mask_state.h"

typedef struct {
    u8 pad000[0x690];
    s16 f690[10];
    s16 f6A4[10];
    u8 pad6B8[0x3C];
    s16 f6F4[10];
    s16 f708[10];
    u8 pad71C[0xA];
    u8 f726[10];
    u8 f730[10];
} RosterStats;

typedef struct {
    u8 pad0[0x44];
    s8 f44;
    s8 f45;
    s8 f46;
    s8 f47;
    s8 f48;
    s8 f49;
} WeightedScore;

extern struct Roster D_001E0DF8;

s32 func_L00_007691A8(void *unused, s32 slot)
{
    const RosterStats *stats = (const RosterStats *)&D_001E0DF8;
    s32 count1 = stats->f690[slot];
    s32 count2 = stats->f726[slot];
    s32 count3 = stats->f6F4[slot];
    s32 count4 = stats->f730[slot];
    s32 count5 = stats->f708[slot];
    s32 other = stats->f6A4[slot] - count1 - count2 - count3 - count4 - count5;
    const WeightedScore *weight = D_0021E078;
    return other * weight->f44 + count1 * weight->f49 + count2 * weight->f48 +
           count3 * weight->f47 + count4 * weight->f46 + count5 * weight->f45;
}
