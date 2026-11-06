#include "common.h"

typedef struct Object {
    u32 unknown0[2];
    void *vtable;
    u8 unknownC[0x10];
    f32 x;
    f32 y;
    u8 unknown24[0x1C];
    s32 first;
    u32 color1;
    u32 color2;
    u32 color3;
    u16 selected;
    u16 unknown52;
    u8 count;
    u8 unknown55;
    u8 mode;
    u8 unknown57;
    void *resource;
} Object;
extern u8 D_003D3698[];
extern void *func_0050BE90(void *storage);
extern void func_0050DC80(Object *object, s32 selected);
extern void func_0050DE18(Object *object, u32 firstColor, u32 secondColor,
                          u32 thirdColor, u32 fourthColor);

Object *func_0050DAE0(void *storage)
{
    Object *object = storage;
    func_0050BE90(storage);
    object->vtable = D_003D3698;
    object->first = 0;
    object->resource = 0;
    object->color1 = 0x80808080u;
    object->color2 = 0x80808080u;
    object->x = 0.5f;
    object->color3 = 0x80808080u;
    object->y = 0.5f;
    func_0050DC80(object, 0);
    object->unknown52 = 0;
    object->count = 10;
    object->mode = 0;
    object->unknown55 = 0;
    func_0050DE18(object, 0x80808080u, 0, 0, 0);
    return object;
}
