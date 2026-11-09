/* Not matching yet: BYTES 12/428 (tools/try_func.py func_L00_00535680 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 *f0;
    u8 *f4;
    s32 f8;
    s32 fC;
    u8 *f10;
    s32 f14;
} Type1;

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_004FAD28(void *);
extern void func_L00_004F84C8(int, int, int, int, int);
extern void *func_L00_004FACD8(unsigned int);
extern Type1 *func_L00_00535830(void);
extern void func_L00_00535898(Type1 *);
extern s32 func_L00_00535C18(u8 **pp, long *lenOut, s32 *tagOut, s32 *classOut, long remain);

Type1 *func_L00_00535680(Type1 **pobj, u8 **pp, long remain) {
    Type1 *o;
    Type1 *t;
    u8 *buf;
    u8 *p;
    long len;
    s32 tag;
    s32 cls;
    s32 err;

    if (pobj == 0 || (t = *pobj) == 0 || !(t->f14 & 1)) {
        o = func_L00_00535830();
        if (o == 0) {
            return 0;
        }
    } else {
        o = t;
    }
    p = *pp;
    if (func_L00_00535C18(&p, &len, &tag, &cls, remain) & 0x80) {
        err = 0x65;
        goto fail;
    }
    if (remain - (p - *pp) < len) {
        err = 0x65;
        goto fail;
    }
    if (tag != 6) {
        err = 0x72;
        goto fail;
    }
    buf = o->f10;
    if (buf != 0) {
        if (o->fC >= len) {
            goto copy;
        }
        func_004FAD28(buf);
    }
    buf = func_L00_004FACD8(len);
    o->f10 = buf;
    o->f14 |= 8;
    if (buf == 0) {
        err = 0x21;
        goto fail;
    }
copy:
    func_0011A370(buf, p, len);
    o->fC = len;
    o->f0 = 0;
    o->f4 = 0;
    p += len;
    if (pobj != 0) {
        *pobj = o;
    }
    *pp = p;
    return o;
fail:
    func_L00_004F84C8(0xD, 0x81, err, 0, 0);
    if (o != 0 && (pobj == 0 || *pobj != o)) {
        func_L00_00535898(o);
    }
    return 0;
}
