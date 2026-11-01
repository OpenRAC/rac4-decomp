#include "common.h"
extern u8 *D_002233A4;

u32 func_L00_00770590(u8 *p) {
    u8 *obj = *(u8 **)(D_002233A4 + 0x44);
    u32 v;
    obj[0] = 0;
    v = *(u32 *)(p + 0x18);
    *(u32 *)(obj + 4) = v;
    if (v == 0) {
        v = *(u32 *)(p + 0x1C);
        *(u32 *)(obj + 8) = v;
    }
    return v;
}