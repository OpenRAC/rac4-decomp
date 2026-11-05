/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    u64 f0;
    s32 f8;
    s16 f10;
    char _pE[0x6];
    u8 f14;
    char _p15[1];
    u8 f16;
};

extern void func_0011A518(void *, s32, s32);
extern void *func_L00_004FACD8(unsigned int);
extern void func_L00_005535D0(Type1 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern u8 D_004B0A18[];

s32 func_L00_00554480(Type1 *arg0, s64 arg1, u8 *arg2) {
    s32 neg;
    u32 v;
    s32 alloc;
    s32 n;
    s32 i;
    u8 *p;

    arg0->f16 &= ~4;
    if (arg1 == 0) {
        func_L00_005535D0(arg0, 0, 2, (s32)D_004B0A18, 1, 0, 0);
        return 0;
    }
    neg = 0;
    if (arg1 < 0) {
        neg = 1;
        v = -(s32)arg1;
    } else {
        v = (s32)arg1;
    }
    alloc = 0;
    if (arg2 == 0) {
        arg2 = func_L00_004FACD8(8);
        if (arg2 == 0) {
            return 2;
        }
        alloc = 1;
    }
    func_0011A518(arg2, 0, 8);
    n = 1;
    p = arg2 + 6;
    *p = v;
    while (v >= 0x80) {
        v >>= 8;
        p--;
        n++;
        *p = v;
    }
    for (i = 0; i < n; i++) {
        arg2[i] = p[i];
    }
    if (neg) {
        arg2[0] |= 0x80;
    }
    func_L00_005535D0(arg0, 0, 2, (s32)arg2, n, 0, alloc);
    return 0;
}
