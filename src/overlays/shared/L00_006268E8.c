#include "common.h"

extern u8 D_0030CE74[];
extern u8 D_0030D020[];

// Returns the flag byte of the entry for index (D_0030CE74 for 4, else D_0030D020 with 0x200 bytes each).
u8 func_L00_006268E8(s32 arg0) {
    u8 *var_v0;

    if (arg0 == 4) {
        var_v0 = D_0030CE74;
    } else {
        var_v0 = D_0030D020 + (arg0 << 9);
    }
    return *var_v0;
}
