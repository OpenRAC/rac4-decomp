/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 *f14;
    s32 f18;
    s32 f1C;
} Buf;

typedef struct {
    u8 pad[0x20];
    Buf *f20;
    void *f24;
} Obj;

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_L00_004F7228(void *arg0);
extern s32 func_L00_00516AB0(void *o, void *a1, s32 a2);
extern void func_L00_00516E90(Obj *o);

/* buffered write of len bytes from data through o's buffer */
s32 func_L00_00515F80(void *arg0, u8 *data, s32 len) {
    Obj *o = arg0;
    Buf *b;
    s32 total = 0;
    s32 avail;
    s32 n;

    if (data == 0 || len <= 0) {
        return 0;
    }
    b = o->f20;
    if (b == 0 || o->f24 == 0) {
        return 0;
    }
    func_L00_004F7228(o);
loop:
    {
        avail = b->f4 - (b->f18 + b->f1C);
        if (avail >= len) {
            func_0011A370(b->f14 + b->f18, data, len);
            b->f18 += len;
            return total + len;
        }
        if (b->f18 != 0) {
            if (avail > 0) {
                func_0011A370(b->f14 + b->f18, data, avail);
                data += avail;
                len -= avail;
                total += avail;
                b->f18 += avail;
            }
            do {
                n = func_L00_00516AB0(o->f24, b->f14 + b->f1C, b->f18);
                if (n <= 0) {
                    func_L00_00516E90(o);
                    if (n < 0) {
                        return total > 0 ? total : n;
                    }
                    if (n == 0) {
                        return total;
                    }
                }
                b->f1C += n;
                b->f18 -= n;
            } while (b->f18 != 0);
        }
        b->f1C = 0;
        if (len < b->f4) {
            goto loop;
        }
        do {
            n = func_L00_00516AB0(o->f24, data, len);
            if (n <= 0) {
                func_L00_00516E90(o);
                if (n < 0) {
                    return total > 0 ? total : n;
                }
                if (n == 0) {
                    return total;
                }
            }
            total += n;
            data += n;
            len -= n;
            if (len == 0) {
                return total;
            }
        } while (len >= b->f4);
        goto loop;
    }
}
