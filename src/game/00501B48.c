/* cflags: -ffast-math */
#include "common.h"
typedef struct { float a, b, c, d; } Type1;
int D_00220B04 = 0;
extern Type1 D_00335ED0[];
void func_00501B48(float *a, float *b, float *c, float *d) {
    Type1 *p = &D_00335ED0[D_00220B04];
    *a = p->a > *a ? p->a : *a;
    *b = p->b > *b ? p->b : *b;
    *c = p->c < *c ? p->c : *c;
    *d = p->d < *d ? p->d : *d;
}

/* These viewport helpers share the GP-resident view index. */
typedef struct {
    u8 prefix[0x14];
    s32 index;
} Context;
typedef struct {
    s32 first;
    Context *context;
} Manager;
typedef struct {
    f32 x, y, z, w;
} Rect;
extern Manager D_00222038[];
extern Manager *func_005010E0(void);
extern s32 func_00448A68(s32);
extern void *func_00448A20(s32);
extern f32 D_00220B7C, D_00220B80;
extern Rect D_00335EE0[];

extern void func_00501BA0(f32, f32, f32, f32), func_00501BC8(void);
extern s32 *D_0021DDA4;
extern u8 D_00171DEB[];
void func_00501CB8(void)
{
    Manager *m = D_00222038;
    char *state;
    char *p;
    if (!m->context)
        m = func_005010E0();
    state = (char *)m->context;
    p = func_00448A20(func_00448A68(state ? *(s32 *)(state + 0x14) : -1));
    D_00220B04 = 0;
    if (*D_0021DDA4 && D_00171DEB[0])
        func_00501BA0(0.0f, 0.0f, 1.0f, *(f32 *)(p + 0x14));
    else
        func_00501BA0(0.0f, 0.0f, *(f32 *)(p + 0x10), *(f32 *)(p + 0x14));
    func_00501BC8();
}
