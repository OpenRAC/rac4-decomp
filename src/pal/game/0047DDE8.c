#include "pal/interface_state.h"

extern u8 D_0021DEB8[];

u32 func_0047DDE8(u32 index)
{
    u32 override = D_0021DEB8[0];
    if (override) {
        return override + 4;
    }
    if (index < 2) {
        return D_00171C00.values26[index];
    }
    return 0;
}
