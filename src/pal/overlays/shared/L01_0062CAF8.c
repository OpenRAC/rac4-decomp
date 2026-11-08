#include "common.h"

typedef int u128_4B75B0 __attribute__((mode(TI)));
typedef struct { u8 a; u8 pad[3]; u16 id; u8 pad2[58]; u128_4B75B0 v0; u128_4B75B0 v1; } Ent_004B75B0;
extern Ent_004B75B0 D_0034CF60[];

/* PAL: from rac3-decomp's func_L04_004BB348, constants adapted */
s32 func_L01_0062CAF8(u32 id, s32 a1, s32 a2, s32 a3) {
    u8 *e = 0;
    u32 idx = id >> 16;
    if (idx < 12) {
        u8 *p = ((u8 *)&D_0034CF60) + idx * 80;
        if (p[64] != 0 && *(u16 *)(p + 0) == (id & 0xFFFF)) {
            e = p;
        }
    }
    if (e != 0) {
        *(s32 *)(e + 16) = a1;
        *(s32 *)(e + 20) = a2;
        *(s32 *)(e + 24) = a3;
        return 1;
    }
    return 0;
}
