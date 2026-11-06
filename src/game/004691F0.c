#include "common.h"
typedef struct State {
    u8 unknown0[0x1B0];
    s32 selected;
    u8 unknown1B4[0x18];
    s32 state;
    s32 pending;
    u8 unknown1D4[8];
    void *buffer;
} State;
typedef struct Record {
    u8 unknown0[0x24];
    u32 size;
} Record;
extern State D_00171948[];
extern void func_00453658(void *, u32);

s32 func_004691F0(void *buffer, u32 size)
{
    State *state;
    Record *record;
    s32 selected;
    func_00453658(buffer, size);
    state = D_00171948;
    selected = state->selected;
    if (selected == -1)
        return 0;
    record = (Record *)((u32)state + (u32)selected * 0xD4);
    if (size < record->size)
        return 0;
    if (state->state < 0) {
        state->pending = selected;
        state->state = 0x26;
    }
    state->buffer = buffer;
    return state->state == 0x26;
}
