#include "common.h"
#include "pal/object_data.h"

typedef struct PalArenaActor PalArenaActor;
typedef struct {
    u8 pad00[0x4C];
    s32 (*index)(PalArenaActor *);
} PalArenaActorMethods;

struct PalArenaActor {
    u8 pad00[0x14];
    PalArenaActorMethods *methods;
    u8 pad18[0x266D - 0x18];
    u8 active;
    u8 pad266E[0x2F00 - 0x266E];
    u8 *state;
};

typedef struct {
    u8 pad00[0x20];
    f32 f20;
    u8 pad24[4];
    s32 f28;
    s32 f2C;
    f32 f30;
    u8 pad34[4];
    s32 f38;
    u8 pad3C[4];
    f32 f40;
    u8 pad44[4];
    s32 f48;
    u8 pad4C[0x470 - 0x4C];
} PalArenaActorRecord;

extern PalArenaActorRecord D_L41_0022CEC0[];
extern s32 func_00439288(s32 index, u8 *state);

static inline PalArenaActorRecord *actor_record(PalArenaActor *actor) {
    return &D_L41_0022CEC0[actor->methods->index(actor)];
}

/* Initialize three slots for the active linked actor. */
void func_L41_003BDFD0(PalObject *object) {
    u8 *linked;
    PalArenaActor *actor;

    linked = *(u8 **)((u8 *)object->data + 0x268);
    actor = *(PalArenaActor **)(linked + 0x2B8);
    if (actor == 0) {
        return;
    }
    if (actor->active == 0) {
        return;
    }

    func_00439288(0x12, actor->state);
    actor_record(actor)->f20 = 0.3f;
    actor_record(actor)->f28 = 0x14;
    actor_record(actor)->f2C = 0;
    actor_record(actor)->f30 = 0.1f;
    actor_record(actor)->f38 = 0x14;
    actor_record(actor)->f2C = 0;
    actor_record(actor)->f40 = 0.01f;
    actor_record(actor)->f48 = 0x14;
    actor_record(actor)->f2C = 0;
}
