/* Not matching yet: BYTES 5/316 (tools/try_func.py func_L00_0051AA08 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    union {
        s64 l;
        s32 w[2];
    } f0;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
} Type2;

typedef struct {
    s32 f0;
    Type2 **f4;
} Type1;

extern void func_004FAD28(void *);
extern void func_L00_004F84C8(int, int, int, int, int);
extern void *func_L00_004FACD8(unsigned int);
extern Type1 *func_L00_00508028(s32);
extern s32 func_L00_005081E0(Type1 *arg0, s32 arg1);

s32 func_L00_0051AA08(s32 idx, Type1 **pp, s64 a, s32 b, s32 c, s32 d, s32 e) {
    s32 ret = -1;
    Type2 *n;

    if (*pp == 0) {
        if ((*pp = func_L00_00508028(0)) == 0) {
            goto fail;
        }
    }
    n = func_L00_004FACD8(0x18);
    if (n == 0) {
fail:
        func_L00_004F84C8(0x26, 0x64, 0x21, 0, 0);
        goto end;
    }
    n->f0.l = a;
    n->f8 = b;
    n->fC = c;
    n->f14 = d;
    n->f10 = e;
    for (;;) {
        s32 ok;
        if (idx < (*pp)->f0) break;
        ok = func_L00_005081E0(*pp, 0);
        if (ok == 0) {
            func_L00_004F84C8(0x26, 0x64, 0x21, 0, 0);
            func_004FAD28(n);
            goto end;
        }
    }
    (*pp)->f4[idx] = n;
    ret = idx;
end:
    return ret;
}
