/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} Type2;

typedef struct {
    Type2 f0;
    Type2 f14;
    Type2 f28;
} Type7;

typedef struct {
    u8 pad[0x40];
    s32 f40;
    Type2 *f44;
    u8 pad2[0x4C - 0x48];
    s32 f4C;
    s32 *f50;
} Type3;

typedef struct {
    u8 pad[0x10C];
    s32 f10C;
} Type6;

extern void func_00538180(Type2 *);
extern int func_L00_005377B0(Type2 *r, Type2 *a, Type2 *b);
extern int func_L00_00537BB0(Type2 *r, Type2 *a, Type2 *b);
extern int func_L00_00537CE8(Type2 *r, Type2 *m, Type2 *d, Type6 *ctx);
extern void func_L00_00537FB0(Type2 *);
extern Type6 *func_L00_005381D8(void);
extern void func_L00_00538258(Type6 *object);
extern Type2 *func_L00_005383D0(Type2 *a, Type2 *b);
extern s32 func_L00_00538C40(s32, Type2 *, Type2 *, Type2 *, s32, Type6 *);
extern int func_L00_00538DE0(Type2 *r, Type2 *a, Type2 *b, Type6 *ctx);

/* Combines per-factor results into one big number, CRT style. */
s32 func_L00_0051F6F0(Type2 *arg0, Type2 *arg1, Type3 *arg2) {
    Type2 b;
    Type2 c;
    Type2 a;
    Type6 *obj;
    s32 i;
    s32 ret = 1;

    obj = func_L00_005381D8();
    if (obj == NULL) {
        ret = 1;
        goto end;
    }
    obj->f10C = arg2->f4C;
    func_00538180(&a);
    func_00538180(&b);
    func_00538180(&c);
    if (func_L00_00538C40(arg2->f50[0], arg0, arg1, 0, 0, obj) != 0) goto end;
    for (i = 1; i < arg2->f40; i++) {
        if (i < 2) {
            func_L00_005383D0(&c, &arg2->f44[0]);
        } else {
            func_L00_00538DE0(&c, &c, &arg2->f44[(i - 1) * 3], obj);
        }
        if (func_L00_00538C40(arg2->f50[i], &a, arg1, 0, 0, obj) != 0) goto end;
        if (!func_L00_00537BB0(&a, &a, arg0)) goto end;
        if (a.fC) {
            if (!func_L00_005377B0(&a, &a, &arg2->f44[i * 3])) goto end;
            if (a.fC) {
                if (!func_L00_00537CE8(&a, &a, &arg2->f44[i * 3], obj)) goto end;
                if (!func_L00_005377B0(&a, &a, &arg2->f44[i * 3])) goto end;
            }
        }
        if (!func_L00_00538DE0(&b, &a, &arg2->f44[i * 3 + 2], obj)) goto end;
        if (!func_L00_00537CE8(&a, &b, &arg2->f44[i * 3], obj)) goto end;
        if (!func_L00_00538DE0(&b, &a, &c, obj)) goto end;
        if (!func_L00_005377B0(arg0, arg0, &b)) goto end;
    }
    ret = 0;
end:
    if (obj) func_L00_00538258(obj);
    func_L00_00537FB0(&a);
    func_L00_00537FB0(&b);
    func_L00_00537FB0(&c);
    return ret;
}
