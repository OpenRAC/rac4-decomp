#include "common.h"

extern u8 D_00171B61[];
extern u8 D_00171B62[];
extern u8 D_00171B63[];
extern u8 D_00171B64[];
extern u8 D_00171B65[];

s32 func_004C12F0(u32 value)
{
    s32 result = 0;
    switch (value) {
    case 3:
        result = D_00171B63[0];
        break;
    case 1:
        result = D_00171B61[0];
        break;
    case 2:
        result = D_00171B62[0];
        break;
    case 4:
        result = D_00171B64[0];
        break;
    case 5:
        result = D_00171B65[0];
        break;
    }
    return result;
}
