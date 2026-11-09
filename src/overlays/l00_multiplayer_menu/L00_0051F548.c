/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 f0[8];
} Type2;

typedef struct {
    s32 (*f0)(s32, unsigned char *, s32, s32, s32, s32);
} Type4;

typedef struct {
    s32 f0;
    Type2 f4;
    u8 pad[0x48 - 0x24];
    s32 f48;
    u8 pad2[0x58 - 0x4C];
    Type4 *f58;
} Type3;

typedef struct {
    s32 f0;
    s32 f4;
    Type3 *f8;
} Type5;

extern void func_00538180(Type2 *);
extern s32 func_L00_0051F6F0(Type2 *, Type2 *, Type3 *);
extern s32 func_L00_00537F68(Type2 *);
extern void func_L00_00538038(void *);
extern void *func_L00_00538590(unsigned char *s, int len, void *ret);
extern s32 func_L00_005386D0(Type2 *, unsigned char *);

/* Decodes a buffer into a big number, transforms it and writes the result back. */
s32 func_L00_0051F548(Type5 *arg0, s32 arg1, unsigned char *arg2, s32 *arg3, u32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    Type2 a;
    Type2 b;
    Type3 *r;
    s32 n;
    s32 j;
    s32 i;
    s32 ret = 1;

    if (arg1 != 1 && arg1 != 10) {
        return 2;
    }
    func_00538180(&a);
    func_00538180(&b);
    r = arg0->f8;
    n = (func_L00_00537F68(&r->f4) + 7) / 8;
    if (arg4 < n) {
        ret = 1;
        goto end;
    }
    if (r->f58->f0(r->f48, arg2, n, arg5, arg6, arg7) != 0) goto end;
    func_L00_00538590(arg2, n, &a);
    if (func_L00_0051F6F0(&b, &a, r) != 0) goto end;
    i = (func_L00_00537F68(&b) + 7) / 8;
    if (n < i) goto end;
    j = n - func_L00_005386D0(&b, arg2 + (n - i));
    for (i = 0; i < j; i++) {
        arg2[i] = 0;
    }
    ret = 0;
    *arg3 = n;
end:
    func_L00_00538038(&b);
    func_L00_00538038(&a);
    return ret;
}
