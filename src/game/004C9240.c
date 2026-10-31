#include "common.h"

extern u8 D_30D188[];
extern u8 D_30E494[];
extern void func_00497980(s32 arg0);
extern void func_004A1310(void *arg0);
extern void func_004A1358(void *arg0);

// Calls func_004A1358 or func_004A1310 on D_30E494 by arg, sets bit 1 of D_30D188's word at 4, then calls func_00497980(0); if D_30E494's word at 0x50 is below 2 it calls func_00497980(4) instead.
void func_004C9240(s32 arg0) {
    u8 *base;
    u8 *flags;

    base = (u8 *)D_30E494;
    if (*(s32 *)(base + 0x50) >= 2) {
        if (arg0 != 0) {
            func_004A1358(base);
        } else {
            func_004A1310(base);
        }
        flags = (u8 *)D_30D188;
        *(s32 *)(flags + 4) = *(s32 *)(flags + 4) | 2;
        func_00497980(0);
    } else {
        func_00497980(4);
    }
}
