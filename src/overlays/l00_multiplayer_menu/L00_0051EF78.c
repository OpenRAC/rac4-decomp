/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct T3 { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } T3;
typedef struct T4 { u8 pad[0x1C]; s32 f1C; } T4;
typedef struct T1 { T4 *f0; s32 f4; u8 *f8; s32 fC; } T1;

extern void *func_0011A518(void *, s32, s32);
extern void func_00538180(void *);
extern void *func_L00_004FACD8(unsigned int);
extern void func_L00_0051EE60(T1 *);
extern s32 func_L00_005208E8(s32, s32, s32, s32 *, T3 **, s32);
extern s32 func_L00_005209E0(s32, s32, void *);
extern void *func_L00_005381D8(void);
extern void func_L00_00538258(u8 *object);
extern void *func_L00_00538590(s32 s, s32 len, void *ret);
extern s32 func_L00_00538AD8(s32, void *);
extern s32 func_L00_00538B68(s32, void *, s32, s32, u8 *);
extern u8 D_004A1900[];
extern u8 D_004A1920[];

/* loads the menu object's settings from the config source arg1 */
s32 func_L00_0051EF78(T1 *arg0, s32 arg1) {
    T3 *res;
    s32 i;
    s32 sp8;
    s32 ret;
    u8 *obj;
    u8 *h;
    s32 n;
    u8 *arr;
    s32 *arr2;

    ret = 1;
    sp8 = 0;
    obj = arg0->f8;
    if (obj != 0) {
        func_L00_0051EE60(arg0);
    }
    obj = func_L00_004FACD8(0x5C);
    if (obj == 0) {
        return 1;
    }
    func_0011A518(obj, 0, 0x5C);
    arg0->f8 = obj;
    arg0->fC &= ~5;
    i = 0;
    if (func_L00_005209E0(arg1, 0x10, D_004A1900) == 0) {
        i = 1;
        arg0->fC |= 4;
    }
    if (func_L00_005209E0(arg1, 0x10, D_004A1920) == 0) {
        i = 1;
        arg0->fC |= 1;
    }
    if (i == 0) {
        return 4;
    }
    *(s32 *)(obj + 0x58) = arg0->f0->f1C;
    i = 0;
    func_L00_005208E8(arg1, 1, 2, &i, &res, 4);
    *(s32 *)(obj + 0x48) = res ? res->fC : 0;
    func_L00_005208E8(arg1, 1, 3, &i, &res, 4);
    *(s32 *)(obj + 0x4C) = res ? res->fC : 0;
    h = func_L00_005381D8();
    if (h == 0) {
        goto cleanup;
    }
    *(s32 *)(h + 0x10C) = *(s32 *)(obj + 0x4C);
    if (arg0->fC & 4) {
        i = 0;
        func_L00_005208E8(arg1, 0x10, 1, &i, &res, 4);
        if (res == 0) {
            ret = 2;
            goto cleanup;
        }
        n = res->f10;
        *(s32 *)(obj + 0x40) = n;
        arr = func_L00_004FACD8(n * 0x3C);
        if (arr == 0) {
            goto cleanup;
        }
        for (i = 0; i < n * 3; i++) {
            func_00538180(arr + i * 0x14);
        }
        arr2 = func_L00_004FACD8(n * 4);
        if (arr2 == 0) {
            goto cleanup;
        }
        *(s32 **)(obj + 0x50) = arr2;
        for (i = 0; i < n; i++) {
            func_L00_00538AD8(0, &arr2[i]);
        }
        *(u8 **)(obj + 0x44) = arr;
        func_L00_005208E8(arg1, 0x10, 0x12, &i, &res, 4);
        func_L00_00538590(res->fC, res->f10, obj + 0x2C);
        for (i = 0; i < n; i++) {
            func_L00_005208E8(arg1, 0x10, i * 3 + 0x13, &sp8, &res, 4);
            func_L00_00538590(res->fC, res->f10, arr + i * 0x3C);
            func_L00_005208E8(arg1, 0x10, i * 3 + 0x14, &sp8, &res, 4);
            if (res == 0) {
                goto cleanup;
            }
            func_L00_00538590(res->fC, res->f10, arr + (i * 0x3C + 0x14));
            if (i != 0) {
                func_L00_005208E8(arg1, 0x10, i * 3 + 0x15, &sp8, &res, 4);
                if (res == 0) {
                    goto cleanup;
                }
                func_L00_00538590(res->fC, res->f10, arr + (i * 0x3C + 0x28));
            }
            if (func_L00_00538B68(arr2[i], arr + i * 0x3C, 1, 0, h) != 0) {
                goto cleanup;
            }
            if (func_L00_00538B68(arr2[i], arr + (i * 0x3C + 0x14), 3, 0, h) != 0) {
                goto cleanup;
            }
        }
    }
    i = 0;
    func_L00_005208E8(arg1, 0x10, 0x10, &i, &res, 4);
    func_L00_00538590(res->fC, res->f10, obj + 4);
    if (arg0->fC & 1) {
        func_L00_005208E8(arg1, 0x10, 0x11, &i, &res, 4);
        if (res == 0) {
            goto cleanup;
        }
        func_L00_00538590(res->fC, res->f10, obj + 0x18);
        func_L00_00538AD8(0, obj + 0x54);
        if (func_L00_00538B68(*(s32 *)(obj + 0x54), obj + 4, 1, 0, h) != 0) {
            goto cleanup;
        }
        if (func_L00_00538B68(*(s32 *)(obj + 0x54), obj + 0x18, 3, 0, h) != 0) {
            goto cleanup;
        }
    }
    ret = 0;
cleanup:
    if (h != 0) {
        func_L00_00538258(h);
    }
    return ret;
}
