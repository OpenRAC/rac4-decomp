/* cflags: -mno-split-addresses */
#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    u8 pad08[0x18];
    f32 f20;
} PalArenaEffectState;

typedef struct {
    u8 pad00[0x32];
    s16 height;
    u8 pad34[0x78];
    PalArenaEffectState *state;
} PalArenaEffectObject;

extern u8 D_L41_002226A8[];
extern s32 func_004535C0(void *context, const f32 *position, f32 radius, f32 value);
extern void func_L41_0044F0D0(void *obj, f32 scale);
extern void func_L41_0044F408(void *obj, f32 arg1, f32 arg2);

static inline s32 query_arena_effect(PalArenaEffectObject *obj, PalArenaEffectState *state) {
    return func_004535C0(D_L41_002226A8, &state->f20, (f32)obj->height, state->f4 * 2.0f);
}

void func_L41_0044F798(PalArenaEffectObject *obj) {
    PalArenaEffectState *state = obj->state;

    if (state == NULL || query_arena_effect(obj, state) == -1) {
        return;
    }
    func_L41_0044F0D0(obj, 1.0f);
    func_L41_0044F408(obj, state->f0, 0.0f);
}

void func_L41_0044F820(PalArenaEffectObject *obj) {
    PalArenaEffectState *state = obj->state;
    f32 scale;

    if (state == NULL || query_arena_effect(obj, state) == -1) {
        return;
    }
    scale = 1.0f;
    func_L41_0044F0D0(obj, scale);
    func_L41_0044F408(obj, scale, state->f0);
}
