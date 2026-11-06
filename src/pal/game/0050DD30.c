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

typedef struct Transform {
    u32 first, second;
    f32 x, y;
    u32 fifth, sixth;
} Transform;
typedef struct List {
    Resource base;
    Resource *items[104];
    u32 field1E0;
    Resource *selected;
    s32 count;
    u8 flags, pad[3];
    Transform transform;
} List;
extern u8 D_003D3650[];
extern Resource *func_0050CF28(Resource *resource);
extern u32 func_00502638(Resource *resource);
extern void func_0050DEB8(List *list, s32 mask, s32 enabled);
static inline void initializeTransform(Transform *transform)
{
    transform->first = 0;
    transform->second = 0;
    transform->x = 1.0f;
    transform->y = 1.0f;
    transform->fifth = 0;
    transform->sixth = 0;
}
static inline Resource **initializeItems(Resource **begin)
{
    Resource **cursor = begin;
    s32 i;
    for (i = 103; i != -1; i--)
        *cursor++ = 0;
    return begin;
}
List *func_0050DD30(List *list)
{
    Resource **base, **cursor;
    Transform *transform;
    Resource *selected;
    s32 i;
    func_0050CF28(&list->base);
    list->base.methods = D_003D3650;
    base = initializeItems(list->items);
    *(Resource **)((u32)base + 0x1A4) = 0;
    transform = (Transform *)((u32)base + 0x1B0);
    initializeTransform(transform);
    i = 103;
    cursor = list->items + 103;
    for (; i >= 0; i--) {
        *cursor = 0;
        cursor = (Resource **)((u32)cursor - 4);
    }
    selected = list->selected;
    list->field1E0 = 0;
    list->transform.second = 0;
    list->transform.y = 1.0f;
    list->transform.x = 1.0f;
    list->transform.first = 0;
    if (selected != 0)
        func_00502638(selected);
    list->selected = 0;
    list->count = 0;
    func_0050DEB8(list, 1, 0);
    func_0050DEB8(list, 2, 0);
    func_0050DEB8(list, 4, 0);
    func_0050DEB8(list, 8, 0);
    return list;
}
