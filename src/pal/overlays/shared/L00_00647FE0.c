#include "common.h"

typedef struct State {
    u32 unknown;
    s32 group;
} State;

extern s32 func_004A2798(s32 *group, s32 id);
extern s32 func_00506590(s32 handle, u32 resource);
extern s32 func_00506000(s32 handle, s32 visible);

void func_L00_00647FE0(State *state, s32 enabled, s32 count)
{
    func_00506590(func_004A2798(&state->group, 8), 0x7546);
    func_00506590(func_004A2798(&state->group, 7), 0x7546);
    func_00506590(func_004A2798(&state->group, 6), 0x7546);
    func_00506590(func_004A2798(&state->group, 5), 0x7546);
    func_00506590(func_004A2798(&state->group, 4), 0x7546);

    func_00506000(func_004A2798(&state->group, 8), 0);
    func_00506000(func_004A2798(&state->group, 7), 0);
    func_00506000(func_004A2798(&state->group, 6), 0);
    func_00506000(func_004A2798(&state->group, 5), 0);
    func_00506000(func_004A2798(&state->group, 4), 0);

    if (enabled) {
        switch (count) {
        case 5:
            func_00506000(func_004A2798(&state->group, 4), 1);
        case 4:
            func_00506000(func_004A2798(&state->group, 5), 1);
        case 3:
            func_00506000(func_004A2798(&state->group, 6), 1);
        case 2:
            func_00506000(func_004A2798(&state->group, 7), 1);
        case 1:
            func_00506000(func_004A2798(&state->group, 8), 1);
        }
    }
}
