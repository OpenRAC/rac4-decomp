#include "common.h"
typedef struct Block {
    u16 base;
    s16 length;
    u8 used, next, pad[2];
} Block;
typedef struct Instance {
    const void *descriptor;
    f32 frame;
    u8 pad8[6];
    u16 block;
    u8 pad10[5], flags;
} Instance;
typedef struct Resource {
    u8 pad0[8], count, pad9[15];
    const void *data;
} Resource;
extern s32 D_00221574, D_00221570;
extern Block D_0026B0C0[];
extern u8 D_002670C0[];
extern void func_0046A080(const void *, s32, s32);
extern void func_0046A0C0(void);
extern void func_0046E3D8(s32);
extern void func_0046F2C8(const void *, f32);
extern void func_0046F0F0(void *, s32);
void func_00470480(Instance *instance, Resource *resource)
{
    s32 previous = D_00221574;
    s32 index, count = resource->count;
    Block *record, *other;
    if (previous == 0xFF)
        return;
    index = D_00221570;
    if (index == 0xFF)
        return;
    record = (Block *)((u32)D_0026B0C0 + (u32)index * 8);
    while (record->used || record->length < count) {
        index = record->next;
        if (index == 0xFF)
            return;
        record = (Block *)((u32)D_0026B0C0 + (u32)index * 8);
    }
    if (index == 0xFF)
        return;
    if (count < (s16)(u16)record->length) {
        other = (Block *)((u32)D_0026B0C0 + (u32)previous * 8);
        D_00221574 = other->next;
        other->next = record->next;
        record->next = previous;
        other->used = 0;
        other->base = record->base + count;
        other->length = (u16)record->length - count;
    }
    record->length = count;
    record->used = 1;
    func_0046A080(resource->data, count, 0x2000);
    func_0046A0C0();
    func_0046E3D8(count);
    func_0046F2C8(instance->descriptor, instance->frame);
    func_0046F0F0((void *)((u32)D_002670C0 + (u32)(s32)(s16)record->base * 32), count);
    instance->block = index;
    instance->flags |= 4;
}
