#include "common.h"
#include "pal/global_002234A4.h"

extern void *func_L00_0077C0E0(void *, u8 *);
extern u8 D_001DFE0D[];

/* Test the sign of the returned entry's status for the selected slot. */
u32 func_L00_0070CD58(s32 arg0)
{
    s32 temp_a2;
    u32 var_v1;
    void *temp_v0;

    temp_a2 = arg0 * 0x1E0;
    temp_v0 = func_L00_0077C0E0(*(void **)((s8 *)D_002234A4 + 0x5C),
                              D_001DFE0D + temp_a2);
    var_v1 = 0;
    if (temp_v0 != NULL) {
        var_v1 = (u32)~*(s32 *)((s8 *)temp_v0 + 0x18) >> 0x1F;
    }
    return var_v1;
}
