/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

typedef struct {
    u8 pad000[0x218];
    s32 selectedEffect;
    s32 lastEffect;
    u8 pad220[0x10];
    s32 lastFirstEffect;
    s32 previousFirstEffect;
    s32 lastSecondEffect;
    s32 previousSecondEffect;
} EffectState;

typedef struct {
    u8 pad00[0xAC];
    EffectState *state;
} EffectObject;

s32 D_L15_002221D4 = 0;
extern s32 D_0021DE40;
extern s16 D_0024798C[];
extern s32 func_L15_004D8480(s32 *previousEffect, s32 count, ...);
extern s32 func_0045DFC8(s16 effect, s16 a, s16 b, s32 c, f32 x, f32 y, f32 z, f32 w);

static inline void enqueue_effect(EffectState *state)
{
    func_0045DFC8((s16)state->selectedEffect, -1, 2, 0, 0.75f, 1.0f, 0.0f, 64.0f);
}

static inline void publish_effect(EffectState *state, s32 *lastInGroup)
{
    *lastInGroup = D_0021DE40;
    *(s32 *)((u8 *)state + 0x21C) = D_0021DE40;
    enqueue_effect(state);
}

void func_L15_004D8758(EffectObject *object)
{
    EffectState *state = object->state;
    s32 selected;

    if ((s32)((u32)D_0021DE40 - 1500U) < state->lastFirstEffect)
        return;
    if ((s32)((u32)D_0021DE40 - 750U) < state->lastEffect)
        return;
    if (D_0024798C[0] != 0)
        return;

    selected = func_L15_004D8480(&state->previousFirstEffect, 4, 0x2B15, 0x2B3D, 0x2B31, 0x2B33);
    state->selectedEffect = selected;
    if (selected >= 0)
        publish_effect(state, (s32 *)((u8 *)state + 0x230));
}

void func_L15_004D8828(EffectObject *object, s32 immediate)
{
    EffectState *state = object->state;
    if (!immediate) {
        if (D_L15_002221D4 & 1)
            state->selectedEffect = 0x2B3A;
        else
            state->selectedEffect = 0x2B39;
    } else {
        state->selectedEffect = 0x2B28;
    }

    if (*(s32 *)((u8 *)state + 0x218) >= 0) {
        state->lastEffect = D_0021DE40;
        enqueue_effect(state);
    }
}

void func_L15_004D88A8(EffectObject *object)
{
    EffectState *state = object->state;
    s32 selected;

    if ((s32)((u32)D_0021DE40 - 1500U) < state->lastSecondEffect)
        return;
    if ((s32)((u32)D_0021DE40 - 750U) < state->lastEffect)
        return;
    if (D_0024798C[0] != 0)
        return;

    selected = func_L15_004D8480(&state->previousSecondEffect, 3, 0x2B17, 0x2B18, 0x2B19);
    state->selectedEffect = selected;
    if (selected >= 0)
        publish_effect(state, (s32 *)((u8 *)state + 0x238));
}
