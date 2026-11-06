#include "common.h"

typedef struct Entry {
    f32 value;
    u8 unknown4[0x20];
    u8 target;
    u8 unknown25[3];
    f32 visibility;
    u8 secondaryTarget;
    u8 unknown2D[3];
    f32 secondary;
} Entry;

extern u8 D_0030702C[];
extern u8 D_003071D8[];
extern s32 func_00506BB8(void);
extern f32 func_0049C260(f32 *value, s32 target);
extern void func_0049C7E8(s32 context, s32 entry);

void func_0049C698(void)
{
    s32 i = 0;
    u32 offset = 0;
    s32 index = func_00506BB8();
    u32 contextOffset = (u32)index << 9;
    Entry *standard = (Entry *)D_003071D8;

    for (; i < 4; i++, standard++, offset += 0x34) {
        Entry *p = (Entry *)(contextOffset + (u32)standard);
        u8 first;
        s32 second;
        s32 third;

        if (index == 4) {
            p = (Entry *)((u32)D_0030702C + offset);
        }
        if (p->visibility == 0.0f && p->target == 0) {
            continue;
        }
        first = func_0049C260(&p->value, 1) != 0.0f;
        second = func_0049C260(&p->visibility, p->target) != 0.0f;
        first = (second | first) != 0;
        third = func_0049C260(&p->secondary, p->secondaryTarget) != 0.0f;
        if (third | first) {
            func_0049C7E8(index, i);
        }
    }
}
