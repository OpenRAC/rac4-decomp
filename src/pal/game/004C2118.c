#include "common.h"

extern u8 D_00171BE1[];
extern u8 D_00171BE2[];
extern u8 D_00171BE3[];
extern u8 D_00171BE4[];
extern u8 D_00171BE5[];

s32 func_004C2118(u32 value)
{
    s32 result = 0;
    switch (value) {
    case 3:
        result = D_00171BE3[0];
        break;
    case 1:
        result = D_00171BE1[0];
        break;
    case 2:
        result = D_00171BE2[0];
        break;
    case 4:
        result = D_00171BE4[0];
        break;
    case 5:
        result = D_00171BE5[0];
        break;
    }
    return result;
}
