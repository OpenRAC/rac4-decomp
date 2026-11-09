/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 *p;
    s32 f4;
    s32 f8;
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
    u8 *f4;
} Type2;

extern void func_L00_004F84C8(int, int, int, int, int);
extern s32 func_L00_00516990(void *, u8 *, s32);
extern Type2 *func_L00_00516F10(void);
extern void func_L00_00516F68(Type2 *);
extern s32 func_L00_00516FC0(Type2 *, s32);
extern void func_L00_00519EC8(void);
extern void func_L00_00519EF0(void);
extern s64 func_L00_00519F20(void);
extern s32 func_L00_00535C18(u8 **pp, s64 *len, s32 *tagOut, s32 *classOut, s64 remain);

/* Reads one tagged record (with nested indefinite parts) from a stream into a growing buffer, then decodes it with the given callback. */
void *func_L00_00534CC8(void *(*xnew)(void), void *(*d2i)(void *, u8 **, s32), void *in, void *x) {
    Type2 *b;
    u8 *p;
    s32 i;
    void *ret = 0;
    Type1 c;
    s32 want = 8;
    s32 eos = 0;
    s32 off = 0;
    s32 len = 0;

    b = func_L00_00516F10();
    if (b == 0) {
        func_L00_004F84C8(0xD, 0x68, 0x21, 0, 0);
        return 0;
    }

    func_L00_00519EC8();
    for (;;) {
        if (want >= len - off) {
            want -= len - off;
            if (!func_L00_00516FC0(b, len + want)) {
                func_L00_004F84C8(0xD, 0x68, 0x21, 0, 0);
                goto err;
            }
            i = func_L00_00516990(in, &b->f4[len], want);
            if (i < 0 && len - off == 0) {
                func_L00_004F84C8(0xD, 0x68, 0x80, 0, 0);
                goto err;
            }
            if (i > 0)
                len += i;
        }

        p = &b->f4[off];
        c.p = p;
        c.inf = func_L00_00535C18(&c.p, &c.slen, &c.tag, &c.xclass, len - off);
        if (c.inf & 0x80) {
            if ((s32)(func_L00_00519F20() & 0xFFF) != 0x89)
                goto err;
            else
                func_L00_00519EF0();
        }
        i = c.p - p;
        off += i;

        if (c.inf & 1) {
            eos++;
            want = 8;
        } else if (eos && c.slen == 0 && c.tag == 0) {
            eos--;
            if (eos <= 0)
                break;
            else
                want = 8;
        } else {
            want = (s32)c.slen;
            if (want > len - off) {
                want -= len - off;
                if (!func_L00_00516FC0(b, len + want)) {
                    func_L00_004F84C8(0xD, 0x68, 0x21, 0, 0);
                    goto err;
                }
                while (want > 0) {
                    i = func_L00_00516990(in, &b->f4[len], want);
                    if (i <= 0) {
                        func_L00_004F84C8(0xD, 0x68, 0x80, 0, 0);
                        goto err;
                    }
                    len += i;
                    want -= i;
                }
            }
            off += (s32)c.slen;
            if (eos <= 0)
                break;
            else
                want = 8;
        }
    }

    p = b->f4;
    ret = d2i(x, &p, off);
err:
    if (b != 0)
        func_L00_00516F68(b);
    return ret;
}
