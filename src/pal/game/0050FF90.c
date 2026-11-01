#include "common.h"

typedef struct {
    u8 pad00[0x40];
    void *data;
} Object;

void func_0050FF90(Object *object, f32 value)
{
    *(f32 *)((u8 *)object->data + 0x48) = value * (5.0f / 6.0f);
}
