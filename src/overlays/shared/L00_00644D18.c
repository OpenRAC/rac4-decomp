#include "common.h"

typedef struct State {
    u32 unknown;
    s32 group;
} State;

extern s32 func_006294E0(s32 *group, s32 id);
extern s32 func_0069D5D8(s32 handle, u32 resource);
extern s32 func_0069D028(s32 handle, s32 visible);

void func_L00_00644D18(State *state, s32 enabled, s32 count)
{
    func_0069D5D8(func_006294E0(&state->group, 8), 0x7546);
    func_0069D5D8(func_006294E0(&state->group, 7), 0x7546);
    func_0069D5D8(func_006294E0(&state->group, 6), 0x7546);
    func_0069D5D8(func_006294E0(&state->group, 5), 0x7546);
    func_0069D5D8(func_006294E0(&state->group, 4), 0x7546);

    func_0069D028(func_006294E0(&state->group, 8), 0);
    func_0069D028(func_006294E0(&state->group, 7), 0);
    func_0069D028(func_006294E0(&state->group, 6), 0);
    func_0069D028(func_006294E0(&state->group, 5), 0);
    func_0069D028(func_006294E0(&state->group, 4), 0);

    if (enabled) {
        switch (count) {
        case 5:
            func_0069D028(func_006294E0(&state->group, 4), 1);
        case 4:
            func_0069D028(func_006294E0(&state->group, 5), 1);
        case 3:
            func_0069D028(func_006294E0(&state->group, 6), 1);
        case 2:
            func_0069D028(func_006294E0(&state->group, 7), 1);
        case 1:
            func_0069D028(func_006294E0(&state->group, 8), 1);
        }
    }
}
