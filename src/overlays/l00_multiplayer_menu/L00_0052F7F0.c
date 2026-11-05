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

typedef struct Type3 {
    s32 f0;
    s32 f4;
    s32 f8;
} Type3;

extern void func_L00_004F84C8(int, int, int, int, int);
extern void func_L00_0051D000(s32 object);
extern Type3 *func_L00_0052F9C0(void);
extern void func_L00_0052FA40(Type3 *);
extern s32 func_L00_00534998(void *, Type1 *, s64);
extern s32 func_L00_00536038(void *object);
extern s32 func_L00_005360B8(Type1 *arg0, s64 *arg1);
extern void func_L00_00536348(s32 arg0, s32 arg1);
extern s32 func_L00_005421E0(Type3 *, Type1 *, s64);

Type3 *func_L00_0052F7F0(Type3 **arg0, s32 *arg1, s64 arg2) {
    Type1 st;
    s64 len;
    Type3 *obj;

    len = arg2;
    st.f8 = 4;
    st.f28 = arg1;
    st.f24 = *arg1;
    if (arg0 != NULL && *arg0 != NULL) {
        obj = *arg0;
    } else {
        obj = func_L00_0052F9C0();
        if (obj == NULL) {
            st.f2C = 0x2F;
            goto fail;
        }
    }
    st.f0 = *arg1;
    st.f20 = len ? *arg1 + (s32)len : 0;
    if (func_L00_005360B8(&st, &len) == 0) {
        st.f2C = 0x32;
        goto fail;
    }
    st.f24 = st.f0;
    if (func_L00_005421E0(obj, &st, st.f18.l) == 0) {
        st.f2C = 0x33;
        goto fail;
    }
    st.f18.l -= st.f0 - st.f24;
    st.f24 = st.f0;
    if (func_L00_00534998(&obj->f4, &st, st.f18.l) == 0) {
        st.f2C = 0x34;
        goto fail;
    }
    st.f18.l -= st.f0 - st.f24;
    if (obj->f8 != 0) {
        func_L00_0051D000(obj->f8);
        obj->f8 = 0;
    }
    if (func_L00_00536038(&st) == 0) {
        st.f2C = 0x3A;
        goto fail;
    }
    *arg1 = st.f0;
    if (arg0 != NULL) {
        *arg0 = obj;
    }
    return obj;
fail:
    func_L00_004F84C8(0xD, 0xAA, st.f8, 0, 0);
    func_L00_00536348(*arg1, st.f24 - *arg1);
    if (obj != NULL && (arg0 == NULL || *arg0 != obj)) {
        func_L00_0052FA40(obj);
    }
    return NULL;
}
