#include "common.h"
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
extern Rect *func_00449060(s32);
s32 D_00220B9C = 0;
extern f32 D_00220B7C, D_00220B80;
extern Rect D_00335EE0[];
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
