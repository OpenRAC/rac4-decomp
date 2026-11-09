/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_004FAD28(void *);
extern void func_005362F8(void *);
extern void func_L00_004F84C8(int, int, int, int, int);
extern s32 func_L00_00516FC0(void *, s32);
extern s32 func_L00_00536038(void *object);
extern s32 func_L00_00545F88(void *, void *, s32, s32, s32);
extern s32 func_L00_005463B0(void *, s32);

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s64 f18;
    s32 f20;
    s32 f24;
} Type1;

typedef struct {
    s32 f0;
    s32 f4;
    u8 *f8;
} Type2;

typedef struct {
    s32 f0;
    u8 *f4;
    s32 f8;
} Type3;

typedef struct {
    s32 f0;
    s32 f4;
    void *f8;
} Type4;

/* Reads chunks from a stream into a growing buffer, then hands the buffer to the owner. */
s32 func_L00_005461D8(Type4 *arg0, Type1 *arg1) {
    Type3 buf;
    Type2 *chunk;
    s32 total;
    s32 err;
    s32 cur;

    chunk = NULL;
    buf.f0 = 0;
    buf.f8 = 0;
    buf.f4 = 0;
    if (arg0 == NULL) {
        err = 0x23;
        goto fail;
    }
    total = 0;
    while (1) {
        if (arg1->fC & 1) {
            arg1->f4 = func_L00_005463B0(arg1, arg1->f20 - arg1->f0);
            if (arg1->f4 != 0) {
                break;
            }
        } else if (arg1->f18 <= 0) {
            break;
        }
        cur = arg1->f0;
        arg1->f24 = cur;
        if (func_L00_00545F88(&chunk, arg1, arg1->f20 - cur, arg1->f10, arg1->f14) == 0) {
            err = 0x80D;
            goto fail;
        }
        if (func_L00_00516FC0(&buf, total + chunk->f0) == 0) {
            err = 0x807;
            goto fail;
        }
        func_0011A370(buf.f4 + total, chunk->f8, chunk->f0);
        if (!(arg1->fC & 1)) {
            arg1->f18 -= arg1->f0 - arg1->f24;
        }
        total += chunk->f0;
    }
    if (func_L00_00536038(arg1) != 0) {
        arg0->f0 = total;
        if (arg0->f8 != NULL) {
            func_004FAD28(arg0->f8);
        }
        arg0->f8 = buf.f4;
        if (chunk != NULL) {
            func_005362F8(chunk);
        }
        return 1;
    }
    goto report;
fail:
    arg1->f8 = err;
report:
    func_L00_004F84C8(0xD, 0x67, arg1->f8, 0, 0);
    if (chunk != NULL) {
        func_005362F8(chunk);
    }
    if (buf.f4 != NULL) {
        func_004FAD28(buf.f4);
    }
    return 0;
}
