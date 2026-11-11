#include "common.h"

typedef struct Obj {
    char pad0[0x20];
    u8 unk20;
    char pad21[0x13];
    u16 flags;
    char pad36[0x62];
    s32 unk98;
    char pad9C[0x20];
    s16 unkBC;
} Obj;

typedef struct Slot {
    Obj *a;
    Obj *b;
    char pad8[0x48];
} Slot;

typedef struct Hero {
    char pad0[0x634];
    Obj *obj;
    char pad638[0x22F0 - 0x638];
    Slot slots[6];
    char pad24D0[0x25CC - 0x24D0];
    s32 state;
    char pad25D0[0x2663 - 0x25D0];
    u8 unk2663;
    u8 unk2664;
    char pad2665[3];
    u8 unk2668;
    char pad2669[0x2F10 - 0x2669];
    s32 index;
} Hero;

typedef struct Info {
    char pad0[0x86];
    s16 kind;
} Info;

typedef struct Ent {
    char pad0[0x50];
    Info *info;
    char pad54[0x470 - 0x54];
} Ent;

typedef struct List {
    char pad0[0x84];
    s16 count;
    char pad86[0x1F0 - 0x86];
    Obj *items[1];
} List;

extern void func_005239C8(Hero *hero);
extern s32 func_00525190(Hero *hero);
extern s32 D_0021DDB4;
extern s32 D_0021EDD4;
extern Ent D_00229C80[];
extern List D_00237000[];

void func_00523780(Hero *hero)
{
    s32 i;

    if (D_0021EDD4 != 1 && D_0021DDB4 != 2) {
        s16 kind = ((Ent *)(hero->index * sizeof(Ent) + (char *)D_00229C80))->info->kind;
        if (kind == 0x17 || kind == 0x13) {
            func_005239C8(hero);
            return;
        }
    }
    hero->obj->flags |= 1;
    if (hero->state != 0x1D && hero->state != 1 && func_00525190(hero) == 0) {
        hero->obj->unk98 = 0;
    }
    for (i = 0; i < 6; i++) {
        if (i == 0 && func_00525190(hero) == 2 && D_0021DDB4 != 2) {
            continue;
        }
        if (D_0021DDB4 == 2) {
            s32 found = 0;
            s32 k;
            for (k = 0; k < D_00237000[0].count; k++) {
                Obj *o = D_00237000[0].items[k];
                if (o != 0 && o->unkBC == 0) {
                    found = 1;
                }
            }
            if (found) {
                continue;
            }
        }
        {
            Hero *s = (Hero *)(i * sizeof(Slot) + (char *)hero);
            if (s->slots[0].a != 0) {
                s->slots[0].a->flags |= 1;
            }
            if (s->slots[0].b != 0) {
                s->slots[0].b->flags |= 1;
            }
        }
    }
    if (*(s32 *)((char *)hero + 0x2318) == 0xF) {
        Obj *o = hero->slots[0].a;
        if (o != 0 && D_0021DDB4 == 0 && hero->unk2663 == 0 && hero->unk2668 == 0 && hero->unk2664 == 0) {
            o->flags &= 0xFFBE;
        }
    }
    if (*(s32 *)((char *)hero + 0x2318) == 1) {
        Obj *o = hero->slots[0].a;
        if (o != 0 && D_0021DDB4 == 0 && o->unk20 != 0) {
            o->flags &= 0xFFBE;
        }
    }
}
