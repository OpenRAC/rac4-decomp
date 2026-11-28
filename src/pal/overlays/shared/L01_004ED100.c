#include "common.h"

typedef struct Entity Entity;

typedef struct {
    u8 pad000[0xD0];
    Entity *children[4];
    u8 pad0E0[0x214];
    Entity *primary;
    u8 pad2F8[0x28];
    s32 request;
    u8 pad324[0x34];
    Entity *fallback;
} LocalState;

struct Entity {
    u8 pad00[0x30];
    u8 field30;
    u8 pad31;
    u16 field32;
    u8 pad34[0x78];
    LocalState *state;
};

s32 func_L01_004ED100(Entity *entity, s32 request)
{
    LocalState *state = entity->state;
    Entity *primary = state->primary;
    Entity **slot;
    Entity *child;
    Entity *fallback;

    state->request = request;
    if (primary != NULL) {
        request = 3;
        primary->field30 = entity->field30;
        state->primary->field32 = entity->field32;
        slot = state->primary->state->children;
        do {
            child = *slot;
            --request;
            if (child != NULL)
                child->field32 = entity->field32;
            ++slot;
        } while (request >= 0);
    } else {
        fallback = state->fallback;
        if (fallback != NULL)
            fallback->field32 = entity->field32;
    }
    return 1;
}
