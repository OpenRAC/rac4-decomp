#include "pal/mask_state.h"
extern u8 *D_0021DFE8;

extern u32 D_002126F4[];

s32 func_0054D5A8(u32 index)
{
    s32 result = 1;

    if (D_0021DFE8 != NULL) {
        u32 mask = D_002126F4[0];

        if (index < 20) {
            result = mask & (result << index);
            if (result != 0) {
                result = 1;
            } else {
                result = 0;
            }
        }
    }
    return result;
}
