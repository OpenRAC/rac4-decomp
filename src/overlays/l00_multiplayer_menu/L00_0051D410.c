/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern char D_004AE220[];
extern char D_004AE230[];
extern char D_004AE240[];
extern char D_004AE250[];
extern char D_004AE268[];
extern char D_004AE278[];
extern char D_004AE290[];

extern s32 func_0011A8A0(char *a, char *b);
extern void func_004FAD28(char *);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
extern s32 func_L00_0051A350(void);
extern void func_L00_0051A628(s32);
extern s32 func_L00_0051D6B8(s32, char *, s64 *, s32);
extern s32 func_L00_0051D878(char *arg0, s32 arg1);
extern s32 func_L00_0051DBC8(s32, char **, char **, char **, s64 *);

s32 func_L00_0051D410(s32 (*fn)(), char *name, s32 arg2, s32 arg3, s32 arg4) {
    char *a;
    char *b;
    char *c;
    s64 d;
    char *e;
    s32 ret;
    s32 obj;

    ret = 0;
    a = NULL;
    b = NULL;
    e = NULL;
    c = NULL;
    for (;;) {
        if (func_L00_0051DBC8(arg2, &a, &b, &c, &d) == 0) {
            goto fail;
        }
        if (func_0011A8A0(a, name) == 0
            || (func_0011A8A0(a, D_004AE220) == 0 && func_0011A8A0(name, D_004AE230) == 0)
            || (func_0011A8A0(a, D_004AE240) == 0 && func_0011A8A0(name, D_004AE230) == 0)
            || (func_0011A8A0(a, D_004AE250) == 0 && func_0011A8A0(name, D_004AE268) == 0)
            || (func_0011A8A0(a, D_004AE278) == 0 && func_0011A8A0(name, D_004AE290) == 0)) {
            break;
        }
        func_004FAD28(a);
        func_004FAD28(b);
        func_004FAD28(c);
    }
    obj = func_L00_0051A350();
    if (obj != 0 && func_L00_0051D878(b, obj) != 0 && func_L00_0051D6B8(obj, c, &d, arg4) != 0) {
        e = c;
        if (func_0011A8A0(name, D_004AE230) != 0) {
            goto other;
        }
        if (func_0011A8A0(a, D_004AE220) == 0) {
            ret = fn(6, arg3, &e, d);
        } else if (func_0011A8A0(a, D_004AE240) == 0) {
            ret = fn(0x74, arg3, &e, d);
        }
        goto check;
fail:
        return 0;
other:
        ret = fn(arg3, &e, d);
check:
        if (ret == 0) {
            func_L00_004F84C8(9, 0x67, 0x80D, 0, 0);
        }
    }
    func_004FAD28(a);
    func_004FAD28(b);
    func_004FAD28(c);
    if (obj != 0) {
        func_L00_0051A628(obj);
    }
    return ret;
}
