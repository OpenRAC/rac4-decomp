#include "common.h"

extern u8 D_00171DEB[];
extern u8 D_003D74B0[];
extern u8 D_003D7690[];

/* Returns the entry in the D_003D7690 table for arg0 if the flag is set and the entry is non-null, else the D_003D74B0 entry. */
void *func_00448A20(s32 arg0) {
    void *var_v0;

    if ((D_00171DEB[0] == 0) || (var_v0 = ((void **)D_003D7690)[arg0], (var_v0 == NULL))) {
        var_v0 = D_003D74B0 + (arg0 * 0x28);
    }
    return var_v0;
}
