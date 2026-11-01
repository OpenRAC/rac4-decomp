#include "common.h"

u8 func_L00_00640788(u32 index) {
    extern u8 D_004CA390[];
    return D_004CA390[index * 0x14];
}
