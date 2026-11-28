#include "common.h"
#include "pal/mask_state.h"
#include "pal/profile_001721E0.h"

typedef struct {
    u8 pad00[0x104];
    u8 f104[10];
    u8 pad10E[0x174 - 0x10E];
    s32 f174[10];
} Type1;

s32 func_L00_0073E8E8(void *unused, s32 value)
{
    Type1 *state = (Type1 *)D_0021E070;
    s32 i;

    if (state != NULL) {
        const Type4 *profile = &D_001721E0;

        for (i = 0; i < 10; i++) {
            if (state->f104[i] != 255 &&
                (state->f174[i] == value || profile->region20.words.f34 == value)) {
                return 1;
            }
        }
    }
    return 0;
}
