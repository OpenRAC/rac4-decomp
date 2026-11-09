/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct T3 { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } T3;
typedef struct Str { s32 *data; s32 len; s32 f8; s32 fC; s32 f10; } Str;
typedef struct Obj {
    s32 f0;
    s32 f4;
    s32 f8;
    Str s0;
    Str s1;
    Str s2;
    Str s3;
    s32 f5C;
    s32 f60;
    s32 f64;
} Obj;
typedef struct T1 { s32 f0; s32 f4; Obj *f8; } T1;

extern void *func_0011A518(void *, s32, s32);
extern void func_00538180(Str *);
extern void *func_L00_004FACD8(unsigned int);
extern s32 func_L00_0051E250(void *object);
extern s32 func_L00_005208E8(s32, s32, s32, s32 *, T3 **, s32);
extern s32 func_L00_00537F68(Str *);
extern void *func_L00_005381D8(void);
extern void func_L00_00538258(u8 *object);
extern void *func_L00_00538590(s32 s, s32 len, void *ret);
extern s32 func_L00_00538AD8(s32, void *);
extern s32 func_L00_00538B68(s32, void *, s32, s32, u8 *);

s32 func_L00_0051E2B8(T1 *arg0, s32 arg1) {
    T3 *res;
    s32 i;
    s32 ret;
    Obj *obj;
    u8 *h;

    ret = 1;
    h = func_L00_005381D8();
    if (h == 0) {
        return 1;
    }
    obj = arg0->f8;
    if (obj != 0) {
        func_L00_0051E250(arg0);
    }
    obj = func_L00_004FACD8(0x68);
    if (obj == 0) {
        goto cleanup;
    }
    func_0011A518(obj, 0, 0x68);
    arg0->f8 = obj;
    func_00538180(&obj->s0);
    func_00538180(&obj->s1);
    func_00538180(&obj->s2);
    func_00538180(&obj->s3);
    obj->f4 = 0;
    i = 0;
    func_L00_005208E8(arg1, 1, 2, &i, &res, 4);
    obj->f5C = res ? res->fC : 0;
    func_L00_005208E8(arg1, 1, 3, &i, &res, 4);
    obj->f60 = res ? res->fC : 0;
    i = 0;
    func_L00_005208E8(arg1, 0x12, 1, &i, &res, 4);
    if (res == 0) {
        goto cleanup;
    }
    func_L00_00538590(res->fC, res->f10, &obj->s0);
    if (obj->s0.len <= 0) {
        goto cleanup;
    }
    if ((obj->s0.data[0] ^ 1) & 1) {
        goto cleanup;
    }
    func_L00_005208E8(arg1, 0x12, 2, &i, &res, 4);
    if (res == 0) {
        goto cleanup;
    }
    func_L00_00538590(res->fC, res->f10, &obj->s1);
    obj->f4 |= 1;
    func_L00_00538AD8(0, &obj->f64);
    if (func_L00_00538B68(obj->f64, &obj->s0, 1, 0, h) != 0) {
        goto cleanup;
    }
    func_L00_005208E8(arg1, 0x12, 5, &i, &res, 4);
    i = func_L00_00537F68(&obj->s0);
    if (res == 0) {
        obj->f8 = i;
    } else {
        obj->f8 = i < res->f10 ? i : res->f10;
    }
    if (func_L00_005208E8(arg1, 0x12, 4, &i, &res, 4) == 0) {
        func_L00_00538590(res->fC, res->f10, &obj->s3);
        obj->f4 |= 4;
    }
    if (func_L00_005208E8(arg1, 0x12, 3, &i, &res, 4) == 0) {
        func_L00_00538590(res->fC, res->f10, &obj->s2);
        obj->f4 |= 2;
    }
    ret = 0;
cleanup:
    if (h != 0) {
        func_L00_00538258(h);
    }
    return ret;
}
