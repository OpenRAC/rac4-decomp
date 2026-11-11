#include "common.h"

typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1036];
} Entry_3E6C58;
extern Entry_3E6C58 D_00230280[];

void func_L01_0051D7F0(s32 player, s32 axes) {
    u8 *e = ((u8 *)&D_00230280) + player * 1136;
    u8 *o = *(u8 **)(e + 80);
    if (*(s16 *)(o + 134) == 0) {
        u8 *p = *(u8 **)(o + 112) + 0x1E0;
        if (axes == -1) {
            *(u32 *)(p + 0x10) |= 3;
        } else {
            *(u32 *)(p + 0x10) |= axes;
        }
    }
}
