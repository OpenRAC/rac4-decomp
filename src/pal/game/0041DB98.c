#include "common.h"

typedef struct Hero Hero;
typedef struct Entity Entity;
typedef struct Vars Vars;
typedef struct HeroVtable {
    u8 unknown0[0x4C];
    s32 (*identifier)(Hero *hero);
} HeroVtable;
struct Hero {
    u8 unknown0[0x14];
    HeroVtable *vtable;
    u8 unknown18[0x25B4];
    s32 state;
    u8 unknown25D0[0x9D];
    u8 active;
};
struct Entity {
    u8 unknown0[0x20];
    u8 state;
    u8 unknown21[2];
    u8 mode;
    u8 unknown24[0x88];
    void *vars;
    u8 unknownB0[0xC];
    s16 classId;
};
struct Vars {
    Entity *target;
    u8 unknown4[8];
    Hero *hero;
    u8 unknown10[0x10];
    Entity *effect;
    u8 unknown24[0xA];
    u8 active;
};

extern s32 D_0021DE24;
extern void func_0041D960(Entity *entity);
extern void func_0041DA48(Entity *entity);
extern Hero *func_00511D08(Hero *hero);
extern void func_004E9CF8(void *first, void *second, s32 flags, s32 reserved, Hero *hero, f32 scale);

void func_0041DB98(Entity *entity)
{
    Vars *vars;
    Hero *hero;

    if (!entity || entity->state == 0xFE || entity->state == 0xFD) {
        return;
    }
    vars = entity->vars;
    hero = vars->hero;
    if (entity->mode >= 0x40) {
        func_0041D960(entity);
    }
    if (!vars->target || vars->target->state == 0xFE ||
        vars->target->state == 0xFD || vars->target->classId != 0x1099) {
        return;
    }
    if (entity->mode >= 0x40) {
        func_0041DA48(entity);
    }
    if (!hero || !hero->active) {
        return;
    }
    if (hero->vtable->identifier(hero) != D_0021DE24 || entity->state != 4 ||
        vars->hero->state == 0xE || !vars->effect || !hero->active || !vars->active) {
        return;
    }
    {
        u32 effect = (u32)vars->effect->vars;
        void *first = (void *)(effect + 0xF0);
        void *second = (void *)(effect + 0x100);
        Hero *activeHero = func_00511D08(hero);
        func_004E9CF8(first, second, 0, 1, activeHero, 1.0f);
    }
}
