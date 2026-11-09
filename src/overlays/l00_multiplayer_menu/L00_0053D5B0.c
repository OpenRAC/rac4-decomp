/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
} Type3;

typedef struct {
    s32 f0;
    s32 f4;
    u8 *f8;
} Type5;

typedef struct {
    u8 *f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    union { s64 v; } f18;
    u8 *f20;
    u8 *f24;
    u8 **f28;
    s32 f2C;
} Type4;

extern void func_005362F8(void *);
extern void func_L00_004F84C8(int, int, int, int, int);
extern s32 func_L00_00519608(void);
extern void func_L00_00519888(void *);
extern void *func_L00_00535300(void *, void *, s64);
extern s32 func_L00_00536038(void *object);
extern s32 func_L00_005360B8(void *arg0, void *arg1);
extern void *func_L00_00538590(unsigned char *s, int len, void *ret);

/* Parses one entry, or a sequence of four entries, from a buffer into a (possibly new) object. */
Type3 *func_L00_0053D5B0(Type3 **arg0, u8 **arg1, s64 arg2) {
    Type4 st;
    Type5 *bs;
    s32 sev;
    Type3 *obj;

    sev = 0x82;
    st.f8 = 4;
    bs = 0;
    st.f28 = arg1;
    st.f24 = *arg1;
    if (arg0 && *arg0) {
        obj = *arg0;
    } else {
        obj = (Type3 *)func_L00_00519608();
        if (obj == 0) {
            st.f2C = 0x24;
            goto fail;
        }
    }
    st.f0 = *arg1;
    st.f20 = arg2 ? st.f0 + arg2 : 0;
    if (arg2 != 0 && (*st.f0 & ~0x20) == 2) {
        st.f18.v = arg2;
        st.f24 = st.f0;
        if (func_L00_00535300(&bs, &st, st.f18.v) == 0) {
            st.f2C = 0x2B;
            goto fail;
        }
        st.f18.v -= st.f0 - st.f24;
        if ((obj->f18 = (s32)func_L00_00538590(bs->f8, bs->f0, (void *)obj->f18)) == 0) goto fail2;
        obj->f8 = 0;
    } else {
        if (func_L00_005360B8(&st, &arg2) == 0) {
            st.f2C = 0x32;
            goto fail;
        }
        st.f24 = st.f0;
        if (func_L00_00535300(&bs, &st, st.f18.v) == 0) {
            st.f2C = 0x33;
            goto fail;
        }
        st.f18.v -= st.f0 - st.f24;
        if ((obj->f18 = (s32)func_L00_00538590(bs->f8, bs->f0, (void *)obj->fC)) == 0) goto fail2;
        st.f24 = st.f0;
        if (func_L00_00535300(&bs, &st, st.f18.v) == 0) {
            st.f2C = 0x38;
            goto fail;
        }
        st.f18.v -= st.f0 - st.f24;
        if ((obj->fC = (s32)func_L00_00538590(bs->f8, bs->f0, (void *)obj->fC)) == 0) goto fail2;
        st.f24 = st.f0;
        if (func_L00_00535300(&bs, &st, st.f18.v) == 0) {
            st.f2C = 0x3B;
            goto fail;
        }
        st.f18.v -= st.f0 - st.f24;
        if ((obj->f10 = (s32)func_L00_00538590(bs->f8, bs->f0, (void *)obj->f10)) == 0) goto fail2;
        st.f24 = st.f0;
        if (func_L00_00535300(&bs, &st, st.f18.v) == 0) {
            st.f2C = 0x3E;
            goto fail;
        }
        st.f18.v -= st.f0 - st.f24;
        if ((obj->f14 = (s32)func_L00_00538590(bs->f8, bs->f0, (void *)obj->f14)) == 0) goto fail2;
        obj->f8 = 1;
    }
    func_005362F8(bs);
    bs = 0;
    if (func_L00_00536038(&st) == 0) {
        st.f2C = 0x46;
        goto fail;
    }
    *arg1 = st.f0;
    if (arg0) {
        *arg0 = obj;
    }
    return obj;
fail2:
    sev = 0x803;
fail:
    func_L00_004F84C8(0xD, 0x8B, sev, 0, 0);
    if (obj && (!arg0 || *arg0 != obj)) {
        func_L00_00519888(obj);
    }
    if (bs) {
        func_005362F8(bs);
    }
    return 0;
}
