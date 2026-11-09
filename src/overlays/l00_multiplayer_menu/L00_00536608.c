/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef union Type2 {
    s64 l;
    s32 w;
} Type2;

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    Type2 f18;
    s32 f20;
    s32 f24;
    s32 *f28;
    s32 f2C;
} Type1;

typedef struct Item {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Item;

typedef struct List {
    s32 f0;
    Item **f4;
} List;

typedef struct Dest {
    s32 f0;
    u8 *f4;
} Dest;

typedef struct Obj {
    s32 f0;
    s32 f4;
    s32 f8;
    Dest *fC;
} Obj;

extern void *func_0011A370(u8 *, u8 *, s32);
extern void func_00536A10(s32);
extern void func_L00_004F84C8(int, int, int, int, int);
extern s32 func_L00_00508208(List *arg0);
extern s32 func_L00_00516FC0(Dest *, s32);
extern s32 func_L00_00536038(void *object);
extern s32 func_L00_005360B8(Type1 *arg0, s64 *arg1);
extern void func_L00_00536348(s32 arg0, s32 arg1);
extern Obj *func_L00_005368C0(void);
extern void func_L00_00536958(Obj *);
extern void *func_L00_00536BE8(void *, Type1 *, s64, void *, void *, s32, s32);
extern s32 func_L00_005463B0(void *, s64);
extern char func_L00_0054651C[];

/* Parses a list object from a buffer, numbering each parsed group of items. */
Obj *func_L00_00536608(Obj **arg0, s32 *arg1, s64 arg2) {
    Type1 st;
    s64 len;
    s32 i;
    s32 n;
    s32 start;
    s32 size;
    Obj *obj;

    n = 0;
    i = 0;
    len = arg2;
    st.f8 = 4;
    st.f28 = arg1;
    st.f24 = *arg1;
    if (arg0 != NULL && *arg0 != NULL) {
        obj = *arg0;
    } else if ((obj = func_L00_005368C0()) == NULL) {
        {
            st.f2C = 0xB0;
            goto fail;
        }
    }
    start = *arg1;
    while (((List *)obj->f4)->f0 > 0) {
        func_00536A10(func_L00_00508208((List *)obj->f4));
    }
    st.f0 = *arg1;
    st.f20 = len ? *arg1 + (s32)len : 0;
    if (func_L00_005360B8(&st, &len) == 0) {
        st.f2C = 0xBB;
        goto fail;
    }
    for (;;) {
        if (!(st.fC & 1)) {
            if (st.f18.l <= 0) {
                break;
            }
        } else if ((st.f4 = func_L00_005463B0(&st, st.f18.l)) != 0) {
            break;
        }
        st.f24 = st.f0;
        if (func_L00_00536BE8(&obj->f4, &st, st.f18.l, func_L00_0054651C + 4,
                              func_00536A10, 0x11, 0) == 0) {
            st.f2C = 0xC0;
            goto fail;
        }
        st.f18.l -= st.f0 - st.f24;
        while (i < ((List *)obj->f4)->f0) {
            ((List *)obj->f4)->f4[i++]->fC = n;
        }
        n++;
    }
    size = st.f0 - start;
    if (func_L00_00516FC0(obj->fC, size) == 0) {
        goto fail;
    }
    func_0011A370(obj->fC->f4, (u8 *)start, size);
    obj->fC->f0 = size;
    obj->f8 = 0;
    if (func_L00_00536038(&st) == 0) {
        st.f2C = 0xCF;
        goto fail;
    }
    *arg1 = st.f0;
    if (arg0 != NULL) {
        *arg0 = obj;
    }
    return obj;
fail:
    func_L00_004F84C8(0xD, 0xA7, st.f8, 0, 0);
    func_L00_00536348(*arg1, st.f24 - *arg1);
    if (obj != NULL && (arg0 == NULL || *arg0 != obj)) {
        func_L00_00536958(obj);
    }
    return NULL;
}
