#include "common.h"

/* Allocates the instance table at *arg0 for arg1 (below 5), clears its fields and runs the three init calls; returns 1, or 0 when arg1 is out of range. */
extern void func_004FF8D0(u8 **a0, s32 a1);
extern void func_004FF8F0(u8 **a0, s32 a1);
extern s32 func_004FF940(s32 arg0);
extern void func_004FFE88(u8 **arg0);

s32 func_004FFA48(u8 **arg0, u32 arg1) {
    s32 i;
    s32 t;
    s32 u;
    u8 *p;

    if (arg1 < 5U) {
        *arg0 = (u8 *)func_004FF940(arg1);
        i = 0;
        do {
            u = i * 4;
            i += 1;
            *(s32 *)(*arg0 + u + 0x18) = 0;
        } while (i < 16);
        i = 0;
        do {
            *(s32 *)(*arg0 + i * 4 + 0x58) = 0;
            i += 1;
        } while (i < 16);
        i = 0;
        do {
            t = i * 4;
            *(s32 *)(*arg0 + t + 0xE4) = 0;
            *(s32 *)(*arg0 + t + 0x124) = 0;
            *(s32 *)(*arg0 + t + 0x164) = 0;
            *(u8 *)(*arg0 + i + 0x1A4) = 0;
            p = *arg0 + i;
            i += 1;
            *(u8 *)(p + 0x1B4) = 0;
        } while (i < 16);
        *(s32 *)(*arg0 + 0x1C4) = 0;
        *(s32 *)(*arg0 + 0x1C8) = 0;
        *(s32 *)(*arg0 + 0x266C) = 0;
        *(s32 *)(*arg0 + 0x1C8) = arg1;
        *(s32 *)(*arg0 + 0x2670) = 0;
        func_004FF8F0(arg0, 0);
        func_004FF8D0(arg0, 0);
        func_004FFE88(arg0);
        return 1;
    }
    return 0;
}
