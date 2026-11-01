#include "pal/interface_state.h"

s32 func_0047DD30(u32 index)
{
    if (index < 11) {
        return D_00171C00.flags11[index] != 0;
    }
    return 0;
}
