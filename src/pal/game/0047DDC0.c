#include "pal/interface_state.h"

s32 func_0047DDC0(u32 index)
{
    if (index < 8) {
        return D_00171C00.flags1C[index] != 0;
    }
    return 0;
}
