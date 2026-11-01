#include "pal/mask_state.h"

extern u32 D_00212774[];

s32 func_0054EB10(u32 index)
{
    s32 result = 1;

    if (D_0021E070 != NULL) {
        u32 mask = D_00212774[0];

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
