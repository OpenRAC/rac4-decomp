/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 f0[8];
} Type2;

typedef struct {
    s32 f0;
    s32 f4;
    s32 (*f8)(s32, unsigned char *, s32, s32, u32, s32);
} Type4;

typedef struct {
    s32 f0;
    Type2 f4;
    u8 pad[0x48 - 0x24];
    s32 f48;
    s32 f4C;
    s32 f50;
    s32 f54;
    Type4 *f58;
} Type3;

typedef struct {
    s32 f0;
    s32 f4;
    Type3 *f8;
} Type5;

typedef struct {
    u8 pad[0x10C];
    s32 f10C;
} Type6;

extern void func_00538180(Type2 *);
extern s32 func_L00_00537F68(Type2 *);
extern void func_L00_00538038(void *);
extern Type6 *func_L00_005381D8(void);
extern void func_L00_00538258(Type6 *);
extern void *func_L00_00538590(unsigned char *s, int len, void *ret);
extern s32 func_L00_005386D0(Type2 *, unsigned char *);
extern s32 func_L00_00538C40(s32, Type2 *, Type2 *, s32, s32, Type6 *);

s32 func_L00_0051FAB8(Type5 *arg0, s32 arg1, unsigned char *arg2, s32 *arg3, u32 arg4, s32 arg5, u32 arg6, s32 arg7) {
    Type2 a;
    Type2 b;
    Type3 *r;
    Type6 *obj = NULL;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    s32 ret = 1;

    if (arg1 != 3) {
        return 2;
    }
    func_00538180(&a);
    func_00538180(&b);
    r = arg0->f8;
    n = (func_L00_00537F68(&r->f4) + 7) / 8;
    if (arg4 < n || n < arg6) goto end;
    ret = r->f58->f8(r->f48, arg2, n, arg5, arg6, arg7);
    if (ret != 0) goto end;
    if (func_L00_00538590(arg2, n, &a) == NULL) goto end;
    obj = func_L00_005381D8();
    if (obj == NULL) {
        ret = 1;
        goto end;
    }
    obj->f10C = r->f4C;
    ret = func_L00_00538C40(r->f54, &b, &a, 0, 0, obj);
    if (ret != 0) goto end;
    i = (func_L00_00537F68(&b) + 7) / 8;
    j = n - i;
    func_L00_005386D0(&b, arg2 + j);
    if (n < i) goto end;
    for (k = 0; k < n - i; k++) {
        arg2[k] = 0;
    }
    ret = 0;
    *arg3 = n;
end:
    if (obj != NULL) {
        func_L00_00538258(obj);
    }
    func_L00_00538038(&b);
    func_L00_00538038(&a);
    return ret;
}
