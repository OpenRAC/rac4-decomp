#include "common.h"

typedef struct {
    u8 unknown0[0x10];
    u8 frameCount;
    u8 unknown11[0xF];
    u8 data[0];
} Animation;
typedef struct {
    u8 unknown0[0x48];
    Animation *animations[0];
} Resource;
typedef struct {
    u8 unknown0[0x24];
    Resource *resource;
    u8 unknown28[0x2D];
    u8 flags55;
} Object;
extern void func_0047C880(Object *, s32, u16);
extern void func_004740D0(Object *, s32, f32);
extern void func_0046FB90(Object *, Animation *, s32, f32, s32);

void func_00474148(Object *object, s32 index, s32 mode, f32 frame)
{
    Animation *animation = ((Resource *)((u32)object->resource + ((u32)index << 2)))->animations[0];
    s32 count = animation->frameCount;
    if ((f32)count <= frame)
        frame = (f32)(count - 1);
    if (frame > 0.0f && frame <= 11.0f)
        func_0047C880(object, index, (u16)(s32)frame);
    if (mode <= 0) {
        func_004740D0(object, index, frame);
    } else {
        animation = ((Resource *)((u32)object->resource + ((u32)index << 2)))->animations[0];
        func_0046FB90(object, animation, index, frame, mode);
        object->flags55 &= 0xFD;
    }
}
