#include "common.h"

typedef struct Row48 {
    u8 unknown0[0x1C];
    s32 active;
    u8 unknown20[0x10];
} Row48;

typedef struct Row80 {
    u8 unknown0[0x44];
    s32 active;
    u8 unknown48[8];
} Row80;

extern Row48 D_00224FD0[];
extern Row80 D_00225210[];
extern u8 *func_0046C1F0(s32 classId, s32 flags);
extern void func_00474368(void *object, s32 state, s32 animation);
extern s32 func_00461970(const void *position, f32 x, f32 y, f32 z, f32 w, f32 size);

void func_00429BE8(u8 *entity, void *data)
{
    u8 *object = func_0046C1F0(0x24EE, 0x80);
    if (object && entity && data) {
        u8 *state;
        s32 i;
        object[0x30] = 0xFF;
        *(u16 *)(object + 0x32) = 0xFF;
        state = *(u8 **)(object + 0xAC);
        func_00474368(object, 0, -1);
        for (i = 11; i >= 0; i--)
            D_00224FD0[i].active = 0;
        for (i = 127; i >= 0; i--)
            D_00225210[i].active = 0;
        *(s32 *)(state + 0x10) = func_00461970(object + 0x10, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        *(u8 **)(state + 0x18) = entity;
        *(s32 *)(state + 0x14) = *(s16 *)(entity + 0xBC);
        *(void **)(state + 0x1C) = data;
    }
}
