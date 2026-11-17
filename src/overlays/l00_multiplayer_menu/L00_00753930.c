#include "common.h"

extern void func_0011A9EC(void *, void *);
extern s32 func_L00_00719B80(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s32);
extern u8 *func_L00_0071AC50(u8 *object);
extern void func_L00_007533F0(void *, s32);
extern u8 *D_00220D14;
extern u8 D_003DB05D[];

s32 D_002213B8 = 0;

// If the menu has no active handle, request a refresh and queue the update; returns 1 when run.
s32 func_L00_00753930(u8 *arg0) {
    u8 *h = *(u8 **)(D_00220D14 + 0x108);
    u8 *r = 0;
    u8 *p;
    if (h != 0) {
        if (h[0xA8] == 1) {
            r = h;
        }
    }
    if (r == 0) {
        p = *(u8 **)(arg0 + 0xCC);
        if (func_L00_00719B80(D_00220D14, p + 0x18, D_003DB05D + D_002213B8 * 0x1E0, 0, 0x10, p[0x49C], p[0x49D], 0, 1) == 1) {
            func_0011A9EC(D_003DB05D + D_002213B8 * 0x1E0, func_L00_0071AC50(*(u8 **)(D_00220D14 + 0x100)));
            func_L00_007533F0(arg0, 0);
        }
        return 1;
    }
    return 0;
}
