#include "common.h"

extern s32 func_L01_00585C00(u8 *object);
extern s32 func_L01_00585CA0(u8 *object);
s32 D_0021EBDC = 0;
// Return 1 and record 2 or 1 when either check passes, otherwise 0.
s32 func_L01_00585BB0(u8 *object) {
    if (func_L01_00585CA0(object) != 0) {
        D_0021EBDC = 2;
        return 1;
    }
    if (func_L01_00585C00(object) != 0) {
        D_0021EBDC = 1;
        return 1;
    }
    return 0;
}
