#include "common.h"

typedef struct { s32 a[4]; } Type9;
extern Type9 D_00222758[];
// Look up a value in a four-entry local table by field 0x69 minus one.
s32 func_L01_0050ADF0(u8 *obj) {
    Type9 t;
    u32 i;
    t = D_00222758[0];
    i = obj[0x69] - 1;
    if (i < 4)
        return t.a[i];
    return -1;
}
