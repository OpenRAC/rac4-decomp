#include "common.h"

extern void *func_L01_006B4FC0(void *a, s32 b, s32 c);
extern void func_006A9B38(void *a, void *b, s32 n);
extern s32 D_00172378[];

/* from rac3-decomp's func_L40_0041B770 */
void func_L01_004D0978(void *moby, s32 type) {
    s32 buf[2];
    void *msg;
    if (type == -1) {
        msg = ((void *(*)(void *, s32, s32, s32))func_L01_006B4FC0)(moby, 1, 0, 250);
    } else {
        msg = ((void *(*)(void *, s32, s32, s32))func_L01_006B4FC0)(moby, 1, 0, -1);
    }
    buf[0] = type;
    func_006A9B38(msg, &buf[0], 4);
    buf[1] = D_00172378[0];
    func_006A9B38(msg, &buf[1], 4);
}
