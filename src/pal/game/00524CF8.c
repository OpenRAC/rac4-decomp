#include "common.h"

typedef struct Hero {
    u8 prefix[0x1F80];
    f32 amount;
    f32 duration;
    s32 value;
    u16 kind;
    u16 flags;
} Hero;

void func_00524CF8(Hero *hero, s16 value, u8 kind, u8 setMask, u8 clearMask, f32 amount, f32 duration)
{
    u16 flags = (hero->flags & ~clearMask) | setMask;
    hero->value = value;
    hero->kind = kind;
    hero->flags = flags;
    hero->amount = amount;
    hero->duration = duration;
}
