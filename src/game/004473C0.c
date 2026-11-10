#include "common.h"

extern u8 *D_0022131C;

u8 *func_004473C0(s32 x, s32 y, s32 z)
{
    u8 *base = D_0022131C;
    u8 *data = base + *(s32 *)base;
    u16 *node = (u16 *)(base + 4);
    s32 iz;
    s32 iy;
    s32 ix;

    iz = z - node[0];
    if (iz < 0) {
        return 0;
    }
    if (!(iz < node[1])) {
        return 0;
    }
    if (!node[iz + 2]) {
        return 0;
    }
    node = (u16 *)(base + node[iz + 2] * 4);
    iy = y - node[0];
    if (iy < 0) {
        return 0;
    }
    if (!(iy < node[1])) {
        return 0;
    }
    if (!node[iy + 2]) {
        return 0;
    }
    node = (u16 *)(base + node[iy + 2] * 4);
    ix = x - node[0];
    if (ix < 0 || !(ix < node[1])) {
        return 0;
    }
    if (node[ix + 2] == 0xFFFF) {
        return 0;
    }
    return data + node[ix + 2] * 128;
}
