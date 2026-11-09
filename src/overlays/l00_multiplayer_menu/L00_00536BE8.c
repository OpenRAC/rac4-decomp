/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 *f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s64 f18;
    u8 *f20;
    u8 *f24;
    u8 **f28;
    s32 f2C;
} Type1;

extern void func_L00_004F84C8(int, int, int, int, int);
extern void *func_L00_00508028(s32);
extern s32 func_L00_005081E0(void *, void *);
extern void func_L00_00508310(void *, void *);
extern void func_L00_00508338(void *);
extern s32 func_L00_00535C18(u8 **pp, s64 *len, s32 *tagOut, s32 *classOut, s64 remain);
extern void func_L00_00536348(s32 arg0, s32 arg1);
extern s32 func_L00_005463B0(void *, s64);

/* Parses a set of elements from a buffer with a per-element callback, appending them to a list. */
void *func_L00_00536BE8(void **a, u8 **pp, s64 length, void *(*d2i)(void *, u8 **, s64, s32),
                        void *free_func, s32 ex_tag, s32 ex_class) {
    Type1 c;
    void *ret;

    if (a == 0 || *a == 0) {
        if ((ret = func_L00_00508028(0)) == 0) {
            goto err;
        }
    } else {
        ret = *a;
    }
    c.f0 = *pp;
    c.f20 = (length == 0) ? 0 : c.f0 + length;
    c.fC = func_L00_00535C18(&c.f0, &c.f18, &c.f10, &c.f14, c.f20 - c.f0);
    if (c.fC & 0x80) {
        goto err;
    }
    if (ex_class != c.f14) {
        func_L00_004F84C8(0xD, 0x84, 0x64, 0, 0);
        goto err;
    }
    if (ex_tag != c.f10) {
        func_L00_004F84C8(0xD, 0x84, 0x69, 0, 0);
        goto err;
    }
    if (c.f20 < c.f0 + c.f18) {
        func_L00_004F84C8(0xD, 0x84, 0x7D, 0, 0);
        goto err;
    }
    if (c.fC == 0x21) {
        c.f18 = length + (*pp - c.f0);
    }
    c.f20 = c.f0 + c.f18;
    while (c.f0 < c.f20) {
        void *s;

        if ((c.fC & 1) == 0 ? (c.f18 <= 0) : (c.f4 = func_L00_005463B0(&c, c.f18))) {
            break;
        }
        if ((s = d2i(0, &c.f0, c.f18, c.f20 - c.f0)) == 0) {
            func_L00_004F84C8(0xD, 0x84, 0x70, 0, 0);
            func_L00_00536348((s32)*pp, c.f24 - *pp);
            goto err;
        }
        if (!func_L00_005081E0(ret, s)) {
            goto err;
        }
    }
    if (a != 0) {
        *a = ret;
    }
    *pp = c.f0;
    return ret;
err:
    if (ret != 0 && (a == 0 || *a != ret)) {
        if (free_func != 0) {
            func_L00_00508310(ret, free_func);
        } else {
            func_L00_00508338(ret);
        }
    }
    return 0;
}
