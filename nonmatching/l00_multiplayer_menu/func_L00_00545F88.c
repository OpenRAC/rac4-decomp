/* Not matching yet: BYTES 11/592 (tools/try_func.py func_L00_00545F88 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
typedef struct {
    u32 f0;
    s32 f4;
    u8 *f8;
} Type4;

typedef struct {
    u8 *f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s64 f18;
    u8 *f20;
    s32 f24;
    u8 **f28;
    s32 f2C;
} Type1;

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_004FAD28(void *);
extern void func_005362F8(void *);
extern void func_L00_004F84C8(int, int, int, int, int);
extern void *func_L00_004FACD8(unsigned int);
extern s32 func_L00_00535C18(u8 **pp, s64 *arg1, s32 *tagOut, s32 *classOut, long remain);
extern Type4 *func_L00_00536270(void);
extern s32 func_L00_005461D8(Type4 *arg0, Type1 *arg1);

/* Parses a tagged byte string from a cursor into a (possibly new) string object. */
Type4 *func_L00_00545F88(Type4 **arg0, u8 **arg1, long arg2, s32 arg3, s32 arg4) {
    Type1 ctx;
    u8 *p;
    s64 len;
    s32 tag;
    s32 cls;
    Type4 *ret;
    u8 *s;
    s32 inf;
    s32 err = 0;

    if (arg0 == NULL || *arg0 == NULL) {
        if ((ret = func_L00_00536270()) == NULL) {
            return NULL;
        }
    } else {
        ret = *arg0;
    }
    p = *arg1;
    inf = func_L00_00535C18(&p, &len, &tag, &cls, arg2);
    if ((inf & 0x80) || arg2 - (p - *arg1) < len) {
        err = 0x65;
        goto fail;
    }
    if (tag != arg3) {
        err = 0x95;
        goto fail;
    }
    if (inf & 0x20) {
        ctx.f28 = arg1;
        ctx.f0 = p;
        ctx.fC = inf;
        ctx.f18 = len;
        ctx.f10 = arg3;
        ctx.f14 = arg4;
        ctx.f20 = (arg2 == 0) ? 0 : p + arg2;
        if (!func_L00_005461D8(ret, &ctx)) {
            goto fail;
        }
        p = ctx.f0;
        goto ok;
    }
    if (len != 0) {
        if (ret->f0 < len + 1 || ret->f8 == NULL) {
            if (ret->f8 != NULL) {
                func_004FAD28(ret->f8);
            }
            s = func_L00_004FACD8((s32)len + 1);
            if (s == NULL) {
                err = 0x21;
                goto fail;
            }
        } else {
            s = ret->f8;
        }
        func_0011A370(s, p, (s32)len);
        s[len] = 0;
        p += len;
    } else {
        s = NULL;
        if (ret->f8 != NULL) {
            func_004FAD28(ret->f8);
        }
    }
    ret->f0 = len;
    ret->f8 = s;
    ret->f4 = arg3;
ok:
    if (arg0 != NULL) {
        *arg0 = ret;
    }
    *arg1 = p;
    return ret;
fail:
    if (ret != NULL && (arg0 == NULL || *arg0 != ret)) {
        func_005362F8(ret);
    }
    func_L00_004F84C8(0xD, 0x7E, err, 0, 0);
    return NULL;
}
