#include "common.h"

typedef struct Type4 {
    char pad0[0xC];
    s32 fC;
} Type4;

typedef struct Type3 {
    char pad0[0x25CC];
    s32 f25CC;
    char pad25D0[0x2EF4 - 0x25D0];
    s32 f2EF4;
    s32 f2EF8;
} Type3;

typedef struct Type2 {
    char pad0[0x2B8];
    Type3 *f2B8;
    Type3 *f2BC;
    char pad2C0[0x324 - 0x2C0];
    Type4 *f324;
    Type3 *f328;
    Type3 *f32C;
} Type2;

typedef struct Type1 {
    char pad0[0x6A];
    u16 f6A;
} Type1;

extern s32 D_0021DDB4;
extern s32 D_0021E824;
extern s32 D_0021E828;
extern Type3 *D_003660F8[];
s32 func_L00_005A00F8(void);
Type2 *func_L00_006EF370(Type1 *);
void func_L00_006EF678(Type2 *, Type3 *);
void func_L00_006EFAA0(Type2 *, Type3 *);

// Assign free players to an object's two slots; returns whether any slot is in use
s32 func_L01_006B36F8(Type1 *arg0, s32 arg1, s32 arg2) {
    s32 i;
    Type3 *p;
    Type2 *obj;
    Type4 *s3;
    s32 mode;

    if (func_L00_005A00F8() || D_0021DDB4) {
        arg0->f6A = 0;
        return 0;
    }
    p = D_003660F8[0];
    i = 0;
    while (i < 10) {
        if (p && (p->f25CC == 0x71 || p->f25CC == 0x63)) {
            arg0->f6A = 0;
            return 0;
        }
        i++;
        p = D_003660F8[i];
    }
    if (arg0->f6A < 6) {
        return 0;
    }
    obj = func_L00_006EF370(arg0);
    mode = D_0021E824;
    if (!obj) {
        return 0;
    }
    s3 = obj->f324;
    if (mode == 1) {
        return obj->f2B8 != 0;
    }
    if (mode == 0 && D_0021E828 == 0 && obj->f2B8) {
        return 1;
    }
    if (mode == 0 && D_0021E828 == 1 && obj->f2B8 && (obj->f2BC || !(s3->fC & 0x100000))) {
        return 1;
    }
    p = D_003660F8[0];
    i = 0;
    while (i < 10) {
        if (p && !p->f2EF4 && !p->f2EF8) {
            if (arg2) {
                arg2 = 0;
            } else if (!obj->f2B8) {
                obj->f328 = p;
                func_L00_006EFAA0(obj, p);
            } else if (!arg1 && !(s3->fC & 0x100000) && !obj->f2BC) {
                obj->f32C = p;
                func_L00_006EF678(obj, p);
            }
        }
        i++;
        p = D_003660F8[i];
    }
    if (!obj->f2B8 && !obj->f2BC && !obj->f328 && !obj->f32C) {
        goto tail;
    }
    return 1;
tail:
    return arg0->f6A >= 6;
}
