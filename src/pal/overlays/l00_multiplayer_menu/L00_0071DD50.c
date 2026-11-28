/* cflags: -fno-strength-reduce */
#include "pal/dialog_71d890.h"
#include "pal/mask_state.h"
#include "pal/profile_001721E0.h"

/* Returns 1 when a profile flag or a live slot name meets the dialog predicate. */
s32 func_L00_0071DD50(void)
{
    u8 *state;
    Type4 *profile;
    s32 i;
    u8 flag;
    u8 *names;
    u8 *teams;
    u8 name;

    state = D_0021E070;
    if (state != 0) {
        profile = &D_001721E0;
        i = 0;
        flag = ((u8 *)profile)[0x251];
        names = state + 0x10E;
        teams = state + 0x104;
        for (; i < 10; i++) {
            if (flag != 0) {
                return 1;
            }
            if (*(s32 *)((u8 *)profile + 0x2DC) != 0) {
                return 1;
            }
            name = names[i];
            if (name >= 7) {
                return 1;
            }
            if (teams[i] == profile->f10 && name == 5) {
                return 1;
            }
        }
    }
    return 0;
}
