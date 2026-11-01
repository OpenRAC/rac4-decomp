/* cflags: -mno-split-addresses */
#include "pal/mask_state.h"

s32 func_00547F68(u32 index)
{
    s32 result = 1;

    if (D_0021E070 != NULL) {
        u32 mask = ((PalMaskState *)D_0021E078)->mask3C;

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
