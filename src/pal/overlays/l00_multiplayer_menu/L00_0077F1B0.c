#include "common.h"
#include "pal/global_002234A4.h"
#include "pal/profile_001721E0.h"

typedef struct {
    u8 pad00[0x11D];
    u8 f11D;
    u8 f11E;
    u8 f11F;
    u8 f120;
} MenuFlags;

typedef struct {
    u8 pad00[0x1D];
    u8 f1D;
    u8 pad1E[0x64 - 0x1E];
    MenuFlags *flags;
} MenuState;

void func_L00_0077F1B0(u32 value)
{
    const MenuState *state = D_002234A4;
    MenuFlags *flags = state->flags;

    if (state->f1D == 0 && value != 0) {
        Type4 *profile = &D_001721E0;

        profile->f2D5 = 1;
        if (flags->f11D != 0) {
            flags->f11E = 1;
            flags->f11D = 0;
            profile->fC = value;
        } else if (flags->f11F != 0) {
            flags->f120 = 1;
            flags->f11F = 0;
            profile->fC = value;
            profile->f2D6 = 1;
        }
    }
}
