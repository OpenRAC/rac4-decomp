#include "common.h"

typedef struct HeroVtable {
    u8 unknown0[0x4C];
    s32 (*identifier)(void *);
} HeroVtable;

extern s32 D_0021EE54;
extern u8 *func_00511CC0(s32 context);
extern u8 *func_00511CF0(s32 context);
extern s32 func_0054BCF0(void *inventory, s32 slot, s32 kind);
extern f32 func_00472EB8(f32 first, f32 last);
extern s32 func_00549710(void *inventory, s32 slot, s32 amount);
extern void func_0054A668(void *inventory, s32 slot, void *object,
                          void *data, s32 identifier, s32 notify);

void func_004331B0(void *object, s32 amount)
{
    f32 value = (f32)amount;
    u8 *data = *(u8 **)((u8 *)object + 0xAC);
    u8 *hero = func_00511CC0(0);
    s32 result;
    if (hero) {
        result = func_0054BCF0(*(void **)(hero + 0x26E4), 8, 6);
        value += (f32)result * 0.5f * value;
    }
    value += func_00472EB8(0.0f, 1.0f);
    hero = func_00511CF0(data[0x16]);
    if (D_0021EE54 != 1) {
        result = func_00549710(*(void **)(hero + 0x26E4), 8, (s32)value);
        if (result) {
            void *entity = *(void **)(hero + 0x22F0);
            HeroVtable *vtable = *(HeroVtable **)(hero + 0x14);
            s32 id = vtable->identifier(hero);
            func_0054A668(*(void **)(hero + 0x26E4), 8, entity,
                          hero + 0x2ED2, id, 1);
        }
    }
}
