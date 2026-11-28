#ifndef PAL_SCENE_SLOT_H
#define PAL_SCENE_SLOT_H

#include "common.h"

typedef struct {
    u8 pad00[0x14];
    s16 f14;
} SceneSlotBinding;

typedef struct {
    u8 pad00[0x40];
    SceneSlotBinding binding;
} SceneSlotObjectData;

typedef struct {
    u8 pad00[0x70];
    SceneSlotObjectData *data;
    u8 pad74[0x12];
    s16 mode;
} SceneSlotObject;

typedef struct {
    u8 pad00[0x50];
    SceneSlotObject *actor;
} SceneSlotPlayer;

typedef struct {
    u8 pad00[4];
    SceneSlotObject *object;
    u8 pad08[0xAA];
    u8 fB2;
    u8 fB3;
    u8 fB4;
    u8 padB5[0x4F];
    u8 f104;
    u8 f105;
    u8 f106;
    u8 pad107;
    s32 f108;
} SceneSlotState;

typedef struct {
    u8 pad00[0x1C];
    SceneSlotState *state;
} SceneSlot;

extern SceneSlot *D_L01_00222A90;

#endif
