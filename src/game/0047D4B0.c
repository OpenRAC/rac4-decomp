
#include "common.h"

typedef struct {
    u8 pad00[0x11];
    u8 flags11[11];
    u8 flags1C[8];
    u8 values24[2];
    u8 values26[2];
} InterfaceState;

extern InterfaceState D_00171B80;


extern u8 D_0021DE30[];

u32 func_0047D4B0(u32 index)
{
    u32 override = D_0021DE30[0];
    if (override) {
        return override + 4;
    }
    if (index < 2) {
        return D_00171B80.values26[index];
    }
    return 0;
}
