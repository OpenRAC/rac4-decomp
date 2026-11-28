#include "common.h"
#include "pal/mask_state.h"
#include "pal/profile_001721E0.h"

extern s32 *D_0021DE2C;
extern s32 D_L00_004B4AC0[];

// Looks up the value for a slot, adjusting the result when the slot is outside the active category.
s32 func_L00_006ACA40(s32 slot) {
    s32 other = 0;
    s32 minimum = -1;
    s32 index;

    if (*D_0021DE2C >= 2 || *(D_0021E070 + slot + 0x104) != D_001721E0.f10) {
        other = 1;
    }
    index = *(D_0021E070 + slot + 0xF0);
    if (index <= minimum) {
        index = 0;
    }

    if (other) {
        if (index >= 20) {
            return D_L00_004B4AC0[index] + 1;
        }
        return D_L00_004B4AC0[index] + 100;
    }
    return D_L00_004B4AC0[index];
}
