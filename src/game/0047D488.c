
#include "common.h"

typedef struct {
    u8 pad00[0x11];
    u8 flags11[11];
    u8 flags1C[8];
    u8 values24[2];
    u8 values26[2];
} InterfaceState;

extern InterfaceState D_00171B80;


s32 func_0047D488(u32 index)
{
    if (index < 8) {
        return D_00171B80.flags1C[index] != 0;
    }
    return 0;
}
