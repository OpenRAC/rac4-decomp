/* cflags: @ee296 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

extern void *func_0011A370(u8 *, u8 *, s32);
extern s32 func_0011D5D8(const char *fmt,...);
extern void func_00126BC0(s32);
extern s32 func_00126BE0(s32);
extern s32 func_0012A718();
extern s32 D_0016F8D4[];
extern s32 *D_0016F8DC[];
extern s32 D_0016F8E4[];
extern char D_001A3F20[];
extern char D_001A3F48[];
extern char D_001A3F78[];
extern s32 D_1B9300[];

// Queues a request into the buffer at D_0016F8DC and returns its handle, or an error code.
s32 func_00152058(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    s32 *p;
    s32 temp_s0;

    if (D_0016F8E4[0] == -1) {
        return 0x8000000A;
    }
    if (arg2 == 0) {
        func_0011D5D8(D_001A3F20);
        return 0x80000004;
    }
    if ((arg3 == NULL) || (D_0016F8D4[0] < *arg3)) {
        func_0011D5D8(D_001A3F48);
        return 0x80000004;
    }
    func_00126BE0(D_0016F8E4[0]);
    p = D_0016F8DC[0];
    p[3] = arg0;
    p[8] = *arg3;
    func_0011A370((u8 *)(p + 12), (u8 *)arg2, *arg3);
    *((u8 *)D_0016F8DC[0] + 0x12) = arg1;
    if (func_0012A718(D_1B9300, 9, 0, D_0016F8DC[0], ((*arg3 + 0x3F) >> 4) << 4,
                      D_0016F8DC[0], 0x30, 0, 0) == 0) {
        temp_s0 = D_0016F8DC[0][0];
        *arg3 = D_0016F8DC[0][8];
        func_00126BC0(D_0016F8E4[0]);
        return temp_s0;
    }
    *arg3 = 0;
    func_0011D5D8(D_001A3F78);
    func_00126BC0(D_0016F8E4[0]);
    return 0x80000000;
}
