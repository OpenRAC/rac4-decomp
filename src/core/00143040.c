/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct State {
    u8 prefix[0x108];
    s32 status;
    u8 unknown10C[0x54];
    s32 kind;
    u8 unknown164[0x20];
    s32 format;
    u8 unknown188[0x40];
    void *block1C8;
    void *block1CC;
    void *block1D0;
    void *block1D4;
    void *block1D8;
    void *block1DC;
    void *block1E0;
    void *block1E4;
    void *block1E8;
    void *block1EC;
    void *block1F0;
    void *block1F4;
} State;

extern void func_001428A0(State *state, void *block, s32 index);
extern void func_00142B60(State *state, void *first, void *second, s32 index);

void func_00143040(State *state, s32 index, s32 enabled)
{
    if (enabled) {
        if (state->format == 3) {
            void *block = state->kind == 3 ? state->block1D4 : state->block1C8;
            func_001428A0(state, block, (s32)((u32)index - 1u));
        } else {
            void *first;
            void *second;

            if (state->kind == 3) {
                first = state->block1E4;
                second = state->block1F4;
            } else {
                first = state->block1D8;
                second = state->block1E8;
            }
            func_00142B60(state, first, second, (s32)((u32)index - 1u));
        }
    }
    if (state->status == 1) {
        state->status = 2;
    }
}
