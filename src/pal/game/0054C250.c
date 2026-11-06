#include "common.h"
typedef struct {
    s32 time;
    s32 type;
    s32 subtype;
    s32 level;
    s32 id;
    s32 bit;
} State;
extern s32 func_0054C330(const State *state);
extern s32 func_0054C100(s32 id, s32 *row);
extern s32 D_00171BCC[];
extern u8 D_00171C88[];
typedef struct {
    u8 unknown0[9];
    u8 unlocked;
    u8 unknownA[2];
} Record;
extern Record D_001F8878[];
s32 func_0054C250(State *state)
{
    if (!func_0054C330(state))
        return 0;
    if (D_00171BCC[0] < state->time)
        return 0;
    if ((u32)state->id + 1 >= 2) {
        s32 row;
        s32 index = func_0054C100(state->id, &row);
        u32 offset = (u32)index * 12 + (u32)((s32)((u32)row - 1) % 20) * 0x304;
        Record *record = (Record *)((u32)D_001F8878 + offset);
        if (!record->unlocked)
            return 0;
    }
    if (state->bit != -1) {
        u32 word = *(u32 *)((u32)D_00171C88 + (((u32)state->bit >> 5) << 2));
        if (!(word & (1u << (state->bit & 31))))
            return 0;
    }
    return 1;
}
