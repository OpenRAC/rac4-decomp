#include "common.h"

typedef struct ContextState {
    u8 active;
    u8 reset;
    u8 unknown2[2];
    u32 wanted;
    u32 enabled;
    u32 retiring;
} ContextState;

typedef struct Entry {
    u32 tag;
    void (*enable)(s32 context);
    void (*disable)(s32 context);
} Entry;

extern u8 D_00306E20[];
extern Entry D_003D8E40[];
extern s32 D_00221680;
extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern s32 func_00506BB8(void);
extern s32 func_0049B0E0(s32 context);
extern s32 func_0049B118(s32 context);
extern void func_0049BE80(s32 context, s32 state);
extern void func_00498D20(s32 context, s32 state);
extern void func_0049B548(s32 context);
extern u32 func_0049ADA0(s32 context);
extern s32 func_00506CA0(u32 handle);
extern void func_00502520(s32 *group);

void func_0049B170(s32 *group)
{
    s32 context = func_00506BB8();
    ContextState *state = (ContextState *)((u32)D_00306E20 + ((u32)context << 4));
    s32 i;
    Entry *entry;
    u32 changed;

    if (context == 0 && D_00221680 > 0)
        --D_00221680;
    if (func_0049B0E0(context)) {
        if (func_0049B118(context)) {
            if (D_0021EE54 == 1) {
                func_0049BE80(context, 1);
                func_00498D20(context, 2);
            } else if (D_0021EE54 != 0 || D_0021EE58 != 1 ||
                       func_0049B0E0(context == 0)) {
                func_0049BE80(0, 1);
                func_00498D20(0, 2);
            }
        }
    }
    if (state->reset) {
        func_0049B548(context);
        func_00506CA0(func_0049ADA0(context));
        func_00502520(group);
        state->reset = 0;
    } else if ((state->enabled & ~state->retiring) != state->wanted) {
        changed = state->enabled ^ state->wanted;
        for (i = 0, entry = D_003D8E40; i < 11; ++i, ++entry) {
            u32 bit = 1U << i;
            if (changed & bit) {
                if (state->wanted & bit) {
                    state->enabled |= bit;
                    if (entry->enable)
                        entry->enable(context);
                } else if (!(state->retiring & bit)) {
                    state->retiring |= bit;
                    if (entry->disable)
                        entry->disable(context);
                }
            }
        }
    }
}
