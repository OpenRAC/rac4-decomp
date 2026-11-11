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

extern void func_L00_004F84C8(int, int, int, int, int);
extern void *func_L00_0052FE48(void);
extern void func_L00_0052FEC8(void *);
extern s32 func_L00_00536038(Type1 *);
extern s32 func_L00_005360B8(Type1 *, s64 *);
extern void func_L00_00536348(u8 *, s32);
extern void *func_L00_00536A78(void *, u8 **, s64);
extern void *func_L00_005421E0(void *, u8 **, s64);

void *func_L00_0052FC90(void **a, u8 **pp, s64 length) {
    Type1 c;
    void **ret;

    c.pp = pp;
    c.q = *pp;
    c.error = 4;
    if (a != NULL && *a != NULL) {
        ret = *a;
    } else if ((ret = func_L00_0052FE48()) == NULL) {
        c.line = 0x29;
        goto err;
    }
    c.p = *pp;
    c.max = (length == 0) ? 0 : c.p + length;
    if (!func_L00_005360B8(&c, &length)) {
        c.line = 0x2C;
        goto err;
    }
    c.q = c.p;
    if (func_L00_005421E0(ret, &c.p, c.slen) == NULL) {
        c.line = 0x2D;
        goto err;
    }
    c.slen -= c.p - c.q;
    c.q = c.p;
    if (func_L00_00536A78(ret + 1, &c.p, c.slen) == NULL) {
        c.line = 0x2E;
        goto err;
    }
    c.slen -= c.p - c.q;
    if (!func_L00_00536038(&c)) {
        c.line = 0x2F;
        goto err;
    }
    *pp = c.p;
    if (a != NULL) *a = ret;
    return ret;
err:
    func_L00_004F84C8(0xD, 0xAE, c.error, 0, 0);
    func_L00_00536348(*pp, c.q - *pp);
    if (ret != NULL && (a == NULL || *a != ret)) func_L00_0052FEC8(ret);
    return NULL;
}
