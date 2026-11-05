/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    u8 *f8;
    s32 fC;
    s64 f10;
} Type1;

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_004FAD28(void *);
extern void func_005362F8(void *);
extern void func_L00_004F84C8(int, int, int, int, int);
extern void *func_L00_004FACD8(unsigned int);
extern s32 func_L00_00535C18(u8 **pp, s64 *len, s32 *tagOut, s32 *classOut, s64 remain);
extern void *func_L00_00536290(s32 arg0);

Type1 *func_L00_00534998(Type1 **a, u8 **pp, s64 length) {
    Type1 *ret;
    u8 *p;
    u8 *s;
    s64 len;
    s32 tag;
    s32 xclass;
    s32 inf;
    s32 i;

    if (a == 0 || *a == 0) {
        ret = func_L00_00536290(3);
        if (ret == 0) {
            return 0;
        }
    } else {
        ret = *a;
    }
    p = *pp;
    inf = func_L00_00535C18(&p, &len, &tag, &xclass, length);
    if (inf & 0x80) {
        i = 0x65;
        goto err;
    }
    if (len > length - (p - *pp)) {
        i = 0x65;
        goto err;
    }
    if (tag != 3) {
        i = 0x74;
        goto err;
    }
    if (len < 1) {
        i = 0x86;
        goto err;
    }
    i = *p++;
    ret->f10 &= ~0xF;
    ret->f10 |= 8 | (i & 7);
    if (len-- > 1) {
        s = func_L00_004FACD8((s32)len);
        if (s == 0) {
            i = 0x21;
            goto err;
        }
        func_0011A370(s, p, (s32)len);
        s[(s32)len - 1] &= (0xFF << i);
        p += (s32)len;
    } else {
        s = 0;
    }
    ret->f0 = (s32)len;
    if (ret->f8 != 0) {
        func_004FAD28(ret->f8);
    }
    ret->f8 = s;
    ret->f4 = 3;
    if (a != 0) {
        *a = ret;
    }
    *pp = p;
    return ret;
err:
    func_L00_004F84C8(0xD, 0x7B, i, 0, 0);
    if (ret != 0 && (a == 0 || *a != ret)) {
        func_005362F8(ret);
    }
    return 0;
}
