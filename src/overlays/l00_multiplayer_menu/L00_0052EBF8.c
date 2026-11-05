/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 *p;
    s32 eos;
    s32 error;
    s32 inf;
    s32 tag;
    s32 xclass;
    s64 slen;
    u8 *max;
    u8 *q;
    u8 **pp;
    s32 line;
} Type1;

typedef struct {
    s32 f0;
    s32 f4;
    u8 *f8;
} Type2;

typedef struct {
    s32 f0;
} Type3;

typedef struct {
    Type2 *f0;
    void *f4;
    void *f8;
    void *fC;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    Type3 *f24;
} Type4;

extern void *func_0052FFD8(void *, Type1 *, s64);
extern void func_005362F8(void *);
extern void func_L00_004F84C8(int, int, int, int, int);
extern void *func_L00_00508208(Type3 *);
extern Type4 *func_L00_0052F190(void);
extern void func_L00_0052F258(void *arg0);
extern void func_L00_0052F3E0(void);
extern void func_L00_0052F6C0(void *object);
extern void *func_L00_0052F7F0(void *, Type1 *, s64);
extern s32 func_L00_00534998(void *, Type1 *, s64);
extern void *func_L00_00535300(void *, Type1 *, s64);
extern s32 func_L00_00535C18(Type1 *, s64 *, s32 *, s32 *, s64);
extern s32 func_L00_00536038(Type1 *);
extern s32 func_L00_005360B8(Type1 *, s64 *);
extern void func_L00_00536348(u8 *, s32);
extern void *func_L00_00536608(void *, Type1 *, s64);
extern void *func_L00_00536BE8(void *, Type1 *, s64, void *, void *, s32, s32);
extern s32 func_L00_005421E0(void *, Type1 *, s64);

/* Decodes a nested record of nine fields from a tagged byte stream. */
Type4 *func_L00_0052EBF8(Type4 **a, u8 **pp, s64 length) {
    s32 ver = 0;
    Type1 c;
    Type4 *ret;

    c.error = 4;
    c.pp = pp;
    c.q = *pp;
    if (a != NULL && *a != NULL) {
        ret = *a;
    } else if ((ret = func_L00_0052F190()) == NULL) {
        c.line = 0x3B;
        goto err;
    }
    c.p = *pp;
    c.max = (length == 0) ? 0 : c.p + length;
    if (!func_L00_005360B8(&c, &length)) {
        c.line = 0x3E;
        goto err;
    }
    if (*c.p == 0xA0) {
        if (c.slen != 0) {
            s32 inf;
            s64 len;
            s32 tag;
            s32 xclass;
            c.q = c.p;
            inf = func_L00_00535C18(&c, &len, &tag, &xclass, c.slen);
            if ((inf & 0x80) || c.slen - (c.p - c.q) < len) {
                c.error = 5;
                c.line = 0x42;
                goto err;
            }
            if (func_L00_00535300(ret, &c, len) == NULL) {
                c.line = 0x42;
                goto err;
            }
            c.slen -= c.p - c.q;
        }
        if (ret->f0->f8 != NULL) {
            ver = ret->f0->f8[0];
        }
    } else {
        if (ret->f0 != NULL) {
            func_005362F8(ret->f0);
            ret->f0 = NULL;
        }
    }
    c.q = c.p;
    if (func_L00_00535300(&ret->f4, &c, c.slen) == NULL) {
        c.line = 0x4E;
        goto err;
    }
    c.slen -= c.p - c.q;
    c.q = c.p;
    if (func_L00_005421E0(&ret->f8, &c, c.slen) == 0) {
        c.line = 0x4F;
        goto err;
    }
    c.slen -= c.p - c.q;
    c.q = c.p;
    if (func_L00_00536608(&ret->fC, &c, c.slen) == NULL) {
        c.line = 0x50;
        goto err;
    }
    c.slen -= c.p - c.q;
    c.q = c.p;
    if (func_0052FFD8(&ret->f10, &c, c.slen) == NULL) {
        c.line = 0x51;
        goto err;
    }
    c.slen -= c.p - c.q;
    c.q = c.p;
    if (func_L00_00536608(&ret->f14, &c, c.slen) == NULL) {
        c.line = 0x52;
        goto err;
    }
    c.slen -= c.p - c.q;
    c.q = c.p;
    if (func_L00_0052F7F0(&ret->f18, &c, c.slen) == NULL) {
        c.line = 0x53;
        goto err;
    }
    c.slen -= c.p - c.q;
    if (ver >= 1) {
        if (ret->f1C != NULL) {
            func_005362F8(ret->f1C);
            ret->f1C = NULL;
        }
        if (ret->f20 != NULL) {
            func_005362F8(ret->f20);
            ret->f20 = NULL;
        }
        if (c.slen != 0 && (*c.p & ~0x20) == 0x81) {
            u8 tmp = *c.p;
            *c.p = (tmp & 0xE0) | 3;
            c.q = c.p;
            if (func_L00_00534998(&ret->f1C, &c, c.slen) == 0) {
                c.line = 0x61;
                goto err;
            }
            c.slen -= c.p - c.q;
            *c.q = tmp;
        }
        if (c.slen != 0 && (*c.p & ~0x20) == 0x82) {
            u8 tmp = *c.p;
            *c.p = (tmp & 0xE0) | 3;
            c.q = c.p;
            if (func_L00_00534998(&ret->f20, &c, c.slen) == 0) {
                c.line = 0x63;
                goto err;
            }
            c.slen -= c.p - c.q;
            *c.q = tmp;
        }
    }
    if (ver >= 2) {
        if (ret->f24 != NULL && ret->f24->f0 != 0) {
            do {
                func_L00_0052F6C0(func_L00_00508208(ret->f24));
            } while (ret->f24->f0 != 0);
        }
        if (c.slen != 0 && *c.p == 0xA3) {
            s32 inf;
            s64 len;
            s32 tag;
            s32 xclass;
            c.q = c.p;
            inf = func_L00_00535C18(&c, &len, &tag, &xclass, c.slen);
            if ((inf & 0x80) || c.slen - (c.p - c.q) < len) {
                c.error = 5;
                c.line = 0x6C;
                goto err;
            }
            if (func_L00_00536BE8(&ret->f24, &c, len, func_L00_0052F3E0, func_L00_0052F6C0, 0x10, 0) == NULL) {
                c.line = 0x6C;
                goto err;
            }
            c.slen -= c.p - c.q;
        }
    }
    if (!func_L00_00536038(&c)) {
        c.line = 0x6E;
        goto err;
    }
    *pp = c.p;
    if (a != NULL) *a = ret;
    return ret;
err:
    func_L00_004F84C8(0xD, 0xA2, c.error, 0, 0);
    func_L00_00536348(*pp, c.q - *pp);
    if (ret != NULL && (a == NULL || *a != ret)) func_L00_0052F258(ret);
    return NULL;
}
