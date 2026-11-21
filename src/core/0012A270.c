/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern int func_00126BA0();
extern int func_00126BB0();
extern void func_00126BE0(s32);
extern s64 func_00129B18(int a1, void *a2, int a3, int a4, int a5, int a6);
extern void *func_00129F58(void *arg0);
extern void func_0012A000(u8 *a0);
extern s32 D_00192FE8[];
extern s32 D_1A7AC0[];

/* Allocates a request object, fills it and sends it, optionally creating a semaphore-like handle first. */
s32 func_0012A270(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4) {
    s32 buf[8];
    s32 ret;
    s32 *p = func_00129F58(D_1A7AC0);

    if (p == 0) {
        ret = -1;
    } else {
        arg0[1] = p[6];
        arg0[0] = (s32)p;
        p[8] = arg1;
        p[9] = arg2;
        p[10] = arg3;
        p[5] = (s32)p;
        p[7] = (s32)arg0;
        if ((arg4 & 1) == 0) {
            buf[1] = 1;
            buf[5] = (s32)D_00192FE8;
            buf[2] = 0;
            arg0[2] = func_00126BA0(buf);
            if (arg0[2] < 0) {
                func_0012A000((u8 *)p);
                ret = -3;
            } else if (func_00129B18(0x8000000C, p, 0x40, 0, 0, 0) == 0) {
                func_0012A000((u8 *)p);
                func_00126BB0(arg0[2]);
                ret = -2;
            } else {
                func_00126BE0(arg0[2]);
                func_00126BB0(arg0[2]);
                ret = 0;
            }
        } else {
            arg0[2] = -1;
            if (func_00129B18(0x8000000C, p, 0x40, 0, 0, 0) == 0) {
                func_0012A000((u8 *)p);
                ret = -2;
            } else {
                ret = 0;
            }
        }
    }
    return ret;
}
