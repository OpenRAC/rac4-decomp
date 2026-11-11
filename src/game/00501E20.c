#include "common.h"

typedef struct Type2 {
    char pad0[0x14];
    s32 f14;
} Type2;

typedef struct Type1 {
    s32 f0;
    Type2 *f4;
} Type1;

typedef struct Type3 {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
} Type3;

extern void *func_00448A20(s32 arg0);
extern s32 func_00448A68(s32);
extern Type1 *func_005010E0(void);

s32 D_00220B04 = 0;
extern f32 D_00220AE4;
extern f32 D_00220AE8;
extern Type1 D_00222038[];
extern Type3 D_00335EE0[];

void func_00501E20(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    Type1 *p;
    s32 id;
    f32 *v;
    Type3 *t;

    if (D_00222038[0].f4 != 0) {
        p = D_00222038;
    } else {
        p = func_005010E0();
    }
    id = -1;
    if (p->f4 != 0) {
        id = p->f4->f14;
    }
    v = func_00448A20(func_00448A68(id));
    t = &D_00335EE0[D_00220B04];
    *arg0 = t->f0 * D_00220AE4 + v[0] * 512.0f;
    *arg1 = t->f8 * D_00220AE4 + v[0] * 512.0f;
    *arg2 = t->f4 * D_00220AE8 + v[2] * 416.0f;
    *arg3 = t->fC * D_00220AE8 + v[2] * 416.0f;
}
