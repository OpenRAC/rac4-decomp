#include "common.h"
typedef struct Object Object;
typedef struct {
    f32 x, y, width, height, anchor_x, anchor_y;
} Rect;
typedef struct {
    u8 unknown0[0x14];
    s32 (*supports)(Object *object, u32 type);
    u8 unknown18[0x10];
    void (*bounds)(Object *object, Rect *input, Rect *output, s32 mode);
} Vtable;
struct Object {
    u32 unknown0, unknown4;
    Vtable *vtable;
};
extern u32 D_00220BF0;
static inline void init(Rect *rect)
{
    rect->x = 0;
    rect->y = 0;
    rect->width = 1;
    rect->height = 1;
    rect->anchor_x = 0;
    rect->anchor_y = 0;
}
s32 func_0050BB78(Object *object, f32 *x, f32 *y, f32 *width, f32 *height)
{
    Rect input;
    Rect output;
    if (object->vtable->supports(object, D_00220BF0)) {
        init(&input);
        init(&output);
        object->vtable->bounds(object, &input, &output, 1);
        *x = output.x;
        *y = output.y;
        *width = output.width;
        *height = output.height;
        return 1;
    }
    return 0;
}
