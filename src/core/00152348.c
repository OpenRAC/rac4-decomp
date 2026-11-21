/* cflags: @ee296 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern s32 func_0011D5D8(const char *fmt,...);
extern void func_00126BE0(s32);
extern s32 func_0012A718();
extern s32 func_0012A918(void *p);
extern void func_00152EC0(void);
extern s32 D_0016F8D4[];
extern s32 *D_0016F8DC[];
extern s32 D_0016F8E4[];
extern char D_001A42B8[];
extern char D_001A42E0[];
extern char D_001A4310[];
extern char D_001A4350[];
extern s32 D_1B9300[];
extern s32 D_1B94B0[];

/* Submits request 9 copying the caller's buffer into the shared buffer; returns a status code. */
s32 func_00152348(s32 arg0, s32 arg1, u8 *arg2, s32 *arg3) {
    s32 *p;

    if (D_0016F8E4[0] == -1) {
        return 0x8000000A;
    }
    if (arg2 == 0) {
        func_0011D5D8(D_001A42B8);
        return 0x80000004;
    }
    if ((arg3 == 0) || (D_0016F8D4[0] < *arg3)) {
        func_0011D5D8(D_001A42E0);
        return 0x80000004;
    }
    if (func_0012A918(D_1B9300) != 0) {
        func_0011D5D8(D_001A4310);
        return 0x80000008;
    }
    func_00126BE0(D_0016F8E4[0]);
    p = D_0016F8DC[0];
    p[3] = arg0;
    p[8] = *arg3;
    *((u8 *)p + 0x12) = arg1;
    D_1B94B0[0] = (s32)arg2;
    D_1B94B0[1] = (s32)arg3;
    func_0011A370((u8 *)(D_0016F8DC[0] + 12), arg2, D_0016F8DC[0][8]);
    if (func_0012A718(D_1B9300, 9, 1, D_0016F8DC[0], ((*arg3 + 0x3F) >> 4) << 4,
                      D_0016F8DC[0], 0x30, func_00152EC0, D_1B94B0) == 0) {
        return 0;
    }
    *arg3 = 0;
    func_0011D5D8(D_001A4350);
    return 0x80000000;
}
