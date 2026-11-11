/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    char _p0[0x4];
    s32 f4;
    char _p8[0x4];
    s32 fC;
} Type1;

typedef struct Item {
    char _p0[0xC];
    s32 fC;
    s32 f10;
} Item;

typedef struct Buf {
    char _p0[0xC];
    s32 fC;
    s32 f10;
    char _p14[0xC];
} Buf;

extern s32 func_L00_0051EE00(s32 arg0, Buf *arg1, s32 arg2, s32 arg3);
extern void func_L00_00520368(Buf *arg0);
extern void func_L00_00520548(Buf *arg0);
extern s32 func_L00_005206A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern s32 func_L00_005208E8(s32, s32, s32, s32, void *, s32);

// Look up entry arg1; copy its two fields out, or zero them and return 1.
s32 func_L00_00519178(Type1 *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    Buf buf;
    Item *item;
    s32 first;

    first = 1;
    item = 0;
loop:
    if (func_L00_005208E8(arg0->f4, 0x12, arg1, 0, &item, 0) == 0) {
        if (arg2 != 0) {
            *arg2 = item->fC;
        }
        if (arg3 != 0) {
            *arg3 = item->f10;
        }
        return 0;
    }
    {
        if (arg0->fC == 0 || first == 0) {
            goto out;
        }
        first = 0;
        func_L00_00520368(&buf);
        if (func_L00_0051EE00(arg0->fC, &buf, arg1, 0) != 0) {
            goto out;
        }
        if (buf.f10 == 0) {
            func_L00_00520548(&buf);
            goto out;
        }
        if (func_L00_005206A8(arg0->f4, 0x12, arg1, 2, buf.fC, buf.f10, 0x12) != 0) {
            func_L00_00520548(&buf);
            goto out;
        }
        func_L00_00520548(&buf);
        goto loop;
    }
out:
    if (arg2 != 0) {
        *arg2 = 0;
    }
    if (arg3 != 0) {
        *arg3 = 0;
    }
    return 1;
}
