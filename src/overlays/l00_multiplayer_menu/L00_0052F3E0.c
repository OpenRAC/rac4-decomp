/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    union { u8 *p; s32 w; } p;
    s32 eos;
    s32 error;
    s32 inf;
    s32 tag;
    s32 xclass;
    union { s64 l; s16 h; } slen;
    u8 *max;
    union { u8 *p; s32 w; } q;
    u8 **pp;
    s32 line;
} Type1;

typedef struct Type2 {
    void *f0;
    s16 f4;
    s16 f6;
    void *f8;
    s32 fC;
    s64 f10;
    u8 *f18;
    void (*f1C)(struct Type2 *);
} Type2;

extern void func_L00_004F84C8(int, int, int, int, int);
extern Type2 *func_L00_0052F630(void);
extern void func_L00_0052F6C0(void *object);
extern s32 func_L00_00534C10(s32 *, Type1 *, s64);
extern s32 func_L00_00535680(void *, Type1 *, s64);
extern s32 func_L00_00536038(void *object);
extern s32 func_L00_005360B8(Type1 *arg0, s64 *arg1);
extern void func_L00_00536348(u8 *arg0, s32 arg1);
extern s32 *func_L00_00536A78(void *, Type1 *, s64);

/* Decodes a record of an identifier, an optional flag and a value from a tagged byte stream. */
Type2 *func_L00_0052F3E0(Type2 **a, u8 **pp, s64 length) {
    Type1 c;
    Type2 *ret;

    c.error = 4;
    c.pp = pp;
    c.q.p = *pp;
    if (a != NULL && *a != NULL) {
        ret = *a;
    } else if ((ret = func_L00_0052F630()) == NULL) {
        c.line = 0x38;
        goto err;
    }
    c.p.p = *pp;
    c.max = (length == 0) ? 0 : c.p.p + length;
    if (!func_L00_005360B8(&c, &length)) {
        c.line = 0x3B;
        goto err;
    }
    c.q.p = c.p.p;
    if (func_L00_00535680(ret, &c, c.slen.l) == 0) {
        c.line = 0x3C;
        goto err;
    }
    c.slen.l -= c.p.p - c.q.p;
    if (ret->f18 != 0 && ret->f1C != NULL) {
        ret->f1C(ret);
    }
    ret->f10 = 0;
    ret->f18 = 0;
    ret->f6 = 0;
    if (c.slen.l != 0 && *c.p.p == 1) {
        s32 i;
        c.q.p = c.p.p;
        if (func_L00_00534C10(&i, &c, c.slen.l) < 0) {
            goto err;
        }
        ret->f4 = i;
        c.slen.l -= c.p.p - c.q.p;
        if (ret->f4 == 0) {
            ret->f6 = 1;
        }
    }
    c.q.p = c.p.p;
    if (func_L00_00536A78(&ret->f8, &c, c.slen.l) == 0) {
        c.line = 0x4C;
        goto err;
    }
    c.slen.l -= c.p.p - c.q.p;
    if (!func_L00_00536038(&c)) {
        c.line = 0x4E;
        goto err;
    }
    *pp = c.p.p;
    if (a != NULL) *a = ret;
    return ret;
err:
    func_L00_004F84C8(0xD, 0xA5, c.error, 0, 0);
    func_L00_00536348(*pp, c.q.p - *pp);
    if (ret != NULL && (a == NULL || *a != ret)) func_L00_0052F6C0(ret);
    return NULL;
}
