/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u64 *d;
    s32 top;
    s32 pad[6];
} Type2;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    Type2 fC;
    u8 pad[0x48 - 0x2C];
    u8 f48[0x1C];
    s32 f64;
} Type3;

typedef struct {
    s32 f0;
    s32 f4;
    Type3 *f8;
} Type5;

extern void func_0011A518(void *, s32, s32);
extern void func_00538180(Type2 *);
extern s32 func_L00_00537F68(Type2 *);
extern void func_L00_00538038(void *);
extern void *func_L00_005381D8(void);
extern void func_L00_00538258(void *);
extern void *func_L00_00538590(unsigned char *s, int len, void *ret);
extern s32 func_L00_005386D0(Type2 *, unsigned char *);
extern s32 func_L00_00538C40(s32, Type2 *, Type2 *, Type2 *, s32, void *);

s32 func_L00_0051E6B8(Type5 *arg0, s32 arg1, unsigned char *arg2, s32 *arg3, u32 arg4, unsigned char *arg5, s32 arg6) {
    Type2 a;
    Type2 b;
    Type3 *r;
    void *ctx;
    u32 n;
    s32 j;
    s32 ret = 1;

    if (arg1 != 6) {
        return 2;
    }
    ctx = func_L00_005381D8();
    if (ctx == 0) {
        return 1;
    }
    func_00538180(&a);
    func_00538180(&b);
    r = arg0->f8;
    if ((r->f4 & 5) != 5) {
        ret = 3;
        goto end;
    }
    n = (func_L00_00537F68(&r->fC) + 7) / 8;
    if (arg4 < n) {
        ret = 4;
        goto end;
    }
    func_L00_00538590(arg5, arg6, &a);
    if (a.top == 0 || (a.top == 1 && a.d[0] == 0) || (a.top == 1 && a.d[0] == 1)) {
        ret = 5;
        goto end;
    }
    ret = func_L00_00538C40(r->f64, &b, &a, (Type2 *)r->f48, 0, ctx);
    if (ret != 0) goto end;
    j = n - (func_L00_00537F68(&b) + 7) / 8;
    if (j != 0) {
        func_0011A518(arg2, 0, j);
    }
    *arg3 = func_L00_005386D0(&b, arg2 + j) + j;
end:
    if (ctx != 0) {
        func_L00_00538258(ctx);
    }
    func_L00_00538038(&a);
    func_L00_00538038(&b);
    return ret;
}
