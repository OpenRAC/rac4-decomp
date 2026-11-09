/* Not matching yet: BYTES 8/376 (tools/try_func.py func_L00_00515E08 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type2 {
    s32 f0;
    s32 f4;
    u8 *f8;
    s32 fC;
    s32 f10;
} Type2;

typedef struct Type1 {
    u8 pad0[0x20];
    Type2 *f20;
    s32 f24;
} Type1;

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_L00_004F7228(Type1 *arg0);
extern s32 func_L00_00516990(s32, u8 *, s32);
extern void func_L00_00516E90(Type1 *);

s32 func_L00_00515E08(Type1 *arg0, u8 *arg1, s32 arg2) {
    Type2 *b;
    s32 total = 0;
    s32 c;

    if (arg1 == NULL) {
        return 0;
    }
    b = arg0->f20;
    if (b == NULL) {
        return 0;
    }
    if (arg0->f24 == 0) {
        return 0;
    }
    func_L00_004F7228(arg0);
loop:
    {
        c = b->fC;
        if (c != 0) {
            if (arg2 < c) {
                c = arg2;
            }
            total += c;
            func_0011A370(arg1, b->f8 + b->f10, c);
            b->f10 += c;
            b->fC -= c;
            if (arg2 == c) {
                return total;
            }
            arg2 -= c;
            arg1 += c;
        }
        if (b->f0 < arg2) {
            for (;;) {
                c = func_L00_00516990(arg0->f24, arg1, arg2);
                if (c <= 0) {
                    func_L00_00516E90(arg0);
                    if (c < 0) {
                        return total > 0 ? total : c;
                    }
                    if (c == 0) {
                        return total;
                    }
                }
                total += c;
                if (arg2 == c) {
                    return total;
                }
                arg1 += c;
                arg2 -= c;
            }
        }
        c = func_L00_00516990(arg0->f24, b->f8, b->f0);
        if (c <= 0) {
            func_L00_00516E90(arg0);
            if (c < 0) {
                return total > 0 ? total : c;
            }
            if (c == 0) {
                return total;
            }
        }
        b->fC = c;
        b->f10 = 0;
        goto loop;
    }
}
