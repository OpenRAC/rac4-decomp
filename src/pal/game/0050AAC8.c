#include "common.h"

typedef struct Object Object;
typedef struct {
    f32 left, top, right, bottom;
    f32 offsetX, offsetY;
} Rectangle;
typedef struct {
    u8 unknown0[0x14];
    s32 (*isType)(Object *, u32);
    u8 unknown18[0x10];
    void (*transform)(Object *, Rectangle *, Rectangle *, s32);
} VTable;
struct Object {
    u8 unknown0[8];
    VTable *vtable;
};
u32 D_00220C00 = 3;

static inline Rectangle *identity(Rectangle *rectangle)
{
    rectangle->left = 0;
    rectangle->top = 0;
    rectangle->right = 1;
    rectangle->bottom = 1;
    rectangle->offsetX = 0;
    rectangle->offsetY = 0;
    return rectangle;
}

static inline s32 transformed(Object *object, f32 *left, f32 *top, f32 *right, f32 *bottom)
{
    Rectangle source;
    Rectangle result;
    {
        Rectangle *out;
        identity(&source);
        out = identity(&result);
        object->vtable->transform(object, &source, out, 1);
    }
    *left = result.left;
    *top = result.top;
    *right = result.right;
    *bottom = result.bottom;
    return 1;
}

s32 func_0050AAC8(Object *object, f32 *left, f32 *top, f32 *right, f32 *bottom)
{
    return object->vtable->isType(object, D_00220C00)
               ? transformed(object, left, top, right, bottom)
               : 0;
}
