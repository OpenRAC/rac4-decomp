#include "common.h"

typedef void (*Action)(s32 cancelled);
typedef struct Entry {
    u8 enabled;
    u8 reserved[3];
    const char *label;
    Action action;
} Entry;
typedef struct State {
    u8 prefix[0x2C];
    s32 selected;
    u8 unknown30[0xC];
    Entry *entries;
    Action close;
} State;

extern u8 D_00307354[];
extern s32 func_00499120(s32 mode);
extern void func_004A08B0(s32 forward);

void func_004A0660(s32 context)
{
    State *state = (State *)((u32)D_00307354 + ((u32)context << 9));
    s32 forward = 0;
    Action action;

    switch (func_00499120(6)) {
    case 1:
        action = ((Entry *)((u32)state->entries + (u32)state->selected * 12u))->action;
        if (action) {
            action(0);
        }
        break;
    case 13:
        if (state->close) {
            state->close(1);
        }
        break;
    case 2:
        if (state->close) {
            state->close(0);
        }
        break;
    case 5:
        forward = 1;
    case 6:
        func_004A08B0(forward);
        break;
    }
}
