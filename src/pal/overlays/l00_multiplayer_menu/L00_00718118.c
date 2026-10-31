#include "common.h"

u32 func_L00_00718118(u32 p) {
    u32 base=p+0x10000;
    u32 idx=*(u32*)(base+0xA60);
    return p+0x860+(idx<<8);
}
