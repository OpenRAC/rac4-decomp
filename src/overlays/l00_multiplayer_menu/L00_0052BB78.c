/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_L00_005195A8(void *arg0, s32 arg1, s32 *arg2);
extern s32 func_L00_0052B040(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, u8 *a6, u8 *a7, s32 a8);
extern s32 func_L00_00540F30(s32 arg0, s32 arg1);

// Copies a block into a local buffer, reads two length-prefixed fields, then calls func_L00_0052B040 with them.
s32 func_L00_0052BB78(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 n, u8 *m) {
    u8 buf[0x40];
    u8 sp50[0x10];
    s32 sp60;
    s32 r;
    u8 *s2;
    u8 *obj;
    u8 *v1;

    s2 = buf;
    func_0011A370(s2, arg3, n);
    s2 = s2 + n;
    if (func_L00_00540F30(*(s32 *)(arg0 + 0x128), arg1) == 0) {
        return 0;
    }
    func_L00_005195A8(*(void **)(arg0 + 0x128), (s32)s2, &sp60);
    s2 = s2 + sp60;
    if (func_L00_00540F30(*(s32 *)(arg0 + 0x128), arg2) == 0) {
        return 0;
    }
    r = 12;
    func_L00_005195A8(*(void **)(arg0 + 0x128), (s32)s2, &sp60);
    v1 = *(u8 **)(arg0 + 0xDC);
    obj = *(u8 **)(arg0 + 0xB0);
    s2 = s2 + sp60;
    if (func_L00_0052B040(*(s32 *)(v1 + 0x104), *(s32 *)(v1 + 0x108), (s32)buf, (s32)(s2 - buf), obj + 0x14, *(s32 *)(obj + 0x10), m, sp50, r) == 0) {
        r = 0;
    }
    return r;
}
