/* cflags: -mno-split-addresses */
#include "pal/mask_state.h"
extern u8 *D_0021DFE8;
extern void *D_0021DFF0;

s32 func_00546A20(u32 index)
{
    s32 result = 1;

    if (D_0021DFE8 != NULL) {
        u32 mask = ((PalMaskState *)D_0021DFF0)->mask3C;

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
