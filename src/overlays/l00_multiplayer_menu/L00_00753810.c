#include "common.h"

extern s32 func_L00_0071AC10(void *arg0);
extern u8 *func_L00_0071AC50(u8 *object);
extern void func_L00_007533F0(void *, s32);
extern void func_0011A9EC(void *, void *);
extern s32 func_L00_00719B80(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s32);
extern void func_L00_0071ABD8(void *, s32);
extern u8 *D_00220D14;
extern u8 D_003DB04D[];
s32 D_002213B8 = 0;

/* Refreshes the menu's handle when none is active and queues the update; returns 0 if one is active. */
s32 func_L00_00753810(u8 *arg0) {
    u8 *h = *(u8 **)(D_00220D14 + 0x108);
    u8 *r = 0;
    u8 *p;
    u8 *obj;
    s32 saved;
    s32 res;
    if (h != 0) {
        if (h[0xA8] == 1) {
            r = h;
        }
    }
    if (r == 0) {
        obj = *(u8 **)(D_00220D14 + 0x100);
        saved = func_L00_0071AC10(obj);
        p = *(u8 **)(arg0 + 0xB0);
        res = func_L00_00719B80(D_00220D14, p + 0x18, D_003DB04D + D_002213B8 * 0x1E0, 0, *(s32 *)(p + 0x128) + 1, 1, p[0x49D], 0, 1);
        func_L00_0071ABD8(obj, saved);
        if (res == 1) {
            func_0011A9EC(D_003DB04D + D_002213B8 * 0x1E0, func_L00_0071AC50(obj));
            func_L00_007533F0(arg0, 0);
        }
        return 1;
    }
    return 0;
}
