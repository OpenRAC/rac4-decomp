/* cflags: -ffast-math */
#include "common.h"
typedef struct { float a, b, c, d; } Type1;
int D_00220B9C = 0;
extern Type1 D_00335ED0[];
void func_00502BB8(float *a, float *b, float *c, float *d) {
    Type1 *p = &D_00335ED0[D_00220B9C];
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
extern Manager D_00222138[];
extern Manager *func_00502150(void);
extern s32 func_004490A8(s32);
extern void *func_00449060(s32);
extern f32 D_00220B7C, D_00220B80;
extern Rect D_00335EE0[];

extern void func_00502C10(f32, f32, f32, f32), func_00502C38(void);
extern s32 *D_0021DE2C;
extern u8 D_00171E6B[];
void func_00502D28(void)
{
    Manager *m = D_00222138;
    char *state;
    char *p;
    if (!m->context)
        m = func_00502150();
    state = (char *)m->context;
    p = func_00449060(func_004490A8(state ? *(s32 *)(state + 0x14) : -1));
    D_00220B9C = 0;
    if (*D_0021DE2C && D_00171E6B[0])
        func_00502C10(0.0f, 0.0f, 1.0f, *(f32 *)(p + 0x14));
    else
        func_00502C10(0.0f, 0.0f, *(f32 *)(p + 0x10), *(f32 *)(p + 0x14));
    func_00502C38();
}

void func_00502E90(s32 *x1, s32 *x2, s32 *y1, s32 *y2)
{
    Manager *manager;
    Rect *view;
    Rect *offset;
    s32 index;
    if (D_00222138[0].context)
        manager = D_00222138;
    else
        manager = func_00502150();
    index = -1;
    if (manager->context)
        index = manager->context->index;
    view = func_00449060(func_004490A8(index));
    offset = &D_00335EE0[D_00220B9C];
    *x1 = (s32)(offset->x * D_00220B7C + view->x * 512.0f);
    *x2 = (s32)(offset->z * D_00220B7C + view->x * 512.0f);
    *y1 = (s32)(offset->y * D_00220B80 + view->z * 448.0f);
    *y2 = (s32)(offset->w * D_00220B80 + view->z * 448.0f);
}
