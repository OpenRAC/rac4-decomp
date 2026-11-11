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

extern u8 D_00306F2C[];
extern u8 D_003070D8[];
extern s32 func_00505B20(void);
extern f32 func_0049B528(f32 *value, s32 target);
extern void func_0049BAB0(s32 context, s32 entry);

void func_0049B960(void)
{
    s32 i = 0;
    u32 offset = 0;
    s32 index = func_00505B20();
    u32 contextOffset = (u32)index << 9;
    Entry *standard = (Entry *)D_003070D8;

    for (; i < 4; i++, standard++, offset += 0x34) {
        Entry *p = (Entry *)(contextOffset + (u32)standard);
        u8 first;
        s32 second;
        s32 third;

        if (index == 4) {
            p = (Entry *)((u32)D_00306F2C + offset);
        }
        if (p->visibility == 0.0f && p->target == 0) {
            continue;
        }
        first = func_0049B528(&p->value, 1) != 0.0f;
        second = func_0049B528(&p->visibility, p->target) != 0.0f;
        first = (second | first) != 0;
        third = func_0049B528(&p->secondary, p->secondaryTarget) != 0.0f;
        if (third | first) {
            func_0049BAB0(index, i);
        }
    }
}
