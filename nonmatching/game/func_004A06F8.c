/* Not matching yet: BYTES 12/376 (tools/try_func.py func_004A06F8 --diff). Not part of the build. */
#include "common.h"

typedef struct Type2 {
    s32 f0;
    s32 f4;
    s32 (*f8)(void *, s32);
    void (*fC)(void *, s32);
} Type2;

typedef struct Type3 {
    Type2 *f0;
} Type3;

typedef struct Type4 {
    s32 f0;
    s32 f4;
    Type2 *f8;
} Type4;

typedef struct Type5 {
    s32 f0[5];
    s32 f14;
} Type5;

typedef struct Type1 {
    s32 f0;
    Type5 *f4;
} Type1;

extern Type1 D_00222038[];

extern s32 func_0015DB80(s32, s32);
extern s32 func_004FF910(s32, s32);
extern s32 func_005005A8(s32, Type4 *, s32);
extern Type1 *func_005010E0(void);
extern Type3 *func_005011A8(Type1 *, s32);
extern void func_00504228(s32);
extern s32 func_00504230(void);
extern Type4 *func_0050D2E8(s32);

static inline Type1 *func_004A06F8_get(void) {
    if (D_00222038->f4 != 0) {
        return D_00222038;
    }
    return func_005010E0();
}

s32 func_004A06F8(s32 arg0) {
    Type5 *q;
    s32 s1;
    s32 s0;
    s32 s2;
    s32 s3;
    Type3 *obj;
    Type4 *o;

    s3 = 0;
    q = func_004A06F8_get()->f4;
    s1 = 0;
    if (q != 0) {
        s1 = q->f0[q->f14];
    }
    func_00504228(0x48);
    s0 = func_00504230();
    if (s1 != 0) {
        if (func_004FF910(s1, arg0) == 0) {
            obj = func_005011A8(func_004A06F8_get(), 1);
            s2 = obj->f0->f8(obj, s0);
            if (s2 != 0) {
                o = func_0050D2E8(func_0015DB80(0x48, s2));
                s3 = func_005005A8(s1, o, arg0) != 0;
                if (s3 == 0) {
                    o->f8->f8(o, 2);
                    obj = func_005011A8(func_004A06F8_get(), 1);
                    obj->f0->fC(obj, s2);
                }
            }
        }
    }
    return s3;
}
