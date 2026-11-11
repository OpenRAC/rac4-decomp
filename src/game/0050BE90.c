#include "common.h"

typedef union FloatWord {
    u32 bits;
    f32 value;
} FloatWord;
typedef struct Flags {
    u32 active : 1, b1 : 1, mode : 2, b4 : 1, b5 : 1, b6 : 1, b7 : 1, b8 : 1, rest : 23;
} Flags;
typedef struct Resource {
    u32 references, reserved;
    const void *methods;
    Flags flags;
    u32 field10;
    FloatWord x, y, width, height, unitx, unity, scale;
    u32 color, blend;
    s32 texture;
    void *field3C;
} Resource;
extern u8 D_003D35D8[];
extern Resource *func_00501598(Resource *resource);
extern void func_0050C058(Resource *resource, s32 x, s32 y);
Resource *func_0050BE90(Resource *resource)
{
    Flags flags;
    func_00501598(resource);
    flags = resource->flags;
    flags.active = 1;
    flags.b1 = 0;
    flags.mode = 3;
    flags.b5 = 0;
    flags.b4 = 0;
    flags.b6 = 0;
    flags.b7 = 0;
    resource->field10 = 0;
    resource->x.bits = 0;
    resource->y.bits = 0;
    resource->width.bits = 0;
    resource->height.bits = 0;
    resource->unitx.bits = 0;
    resource->unity.bits = 0;
    resource->scale.bits = 0;
    resource->methods = D_003D35D8;
    resource->color = 0x80808080;
    resource->blend = 0x80808080;
    flags.b8 = 0;
    resource->flags = flags;
    func_0050C058(resource, 3, 3);
    resource->scale.value = 1.0f;
    resource->x.value = 0.5f;
    resource->y.value = 0.5f;
    resource->width.value = 1.0f;
    resource->height.value = 1.0f;
    resource->unitx.value = 0.00390625f;
    resource->unity.value = 0.0048076925f;
    resource->blend = 0x40000000;
    resource->color = 0xFFFFFFFF;
    resource->texture = -1;
    resource->field3C = 0;
    return resource;
}
