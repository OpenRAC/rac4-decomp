#include "common.h"

typedef struct State {
    u8 dirty;
    u8 unknown1[7];
    s32 enabled;
    s32 previous;
} State;
typedef struct Entry {
    u32 tag;
    void (*enable)(s32 context);
    void (*disable)(s32 context);
} Entry;
extern State D_00306E20[];
extern Entry D_003D8E40[];

void func_0049B548(s32 context)
{
    State *state = (State *)((u32)D_00306E20 + (u32)context * sizeof(State));
    if (state->dirty) {
        s32 i = 0;
        Entry *entry = D_003D8E40;
        state->dirty = 0;
        do {
            if (((state->enabled >> i) & 1) && (((state->previous >> i) ^ 1) & 1)) {
                if (entry->disable) {
                    entry->disable(context);
                }
            }
            i++;
            entry++;
        } while (i < 11);
        state->previous = state->enabled;
    }
}
