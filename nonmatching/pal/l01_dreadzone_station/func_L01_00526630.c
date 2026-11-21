/* Not matching yet on PAL: 22/22 positional words match (100.00%); 0 differ, size 88/88 bytes (delta 0). */
/* cflags:  -Wuninitialized */
/* Relocation fields are masked. Reproduce: tools/check_func.py --version pal func_L01_00526630 nonmatching/pal/l01_dreadzone_station/func_L01_00526630.c --diff
 * The D_00222A90 owner has conflicting declarations; indexed storage and access extent remain unproved. */
#include "common.h"
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

extern int D_00222A90;
extern int D_002303D0[];
s32 func_L01_00526630(s32 arg0) {
    s32 var_4;
    void *temp_3;

    if (M2C_FIELD(D_002303D0[0], s16 *, 0x86) != 0x13) {
        return 0;
    }
    temp_3 = M2C_FIELD(((arg0 << 5) + D_00222A90), void **, 0x1C);
    var_4 = 0;
    if ((M2C_FIELD(temp_3, u8 *, 0x104) != 0) && (M2C_FIELD(temp_3, u8 *, 0x105) != 0)) {
        var_4 = M2C_FIELD(temp_3, u8 *, 0x106) == 0;
    }
    return var_4;
}
