#include "common.h"

typedef struct {
    u8 unknown0[0x40];
    s32 phase;
    s32 changed;
    u8 unknown48[4];
    f32 fade;
} State;
extern State D_00308068[];
extern s32 func_00506BB8(void);
extern s32 func_0049B418(f32 *, f32);
extern void func_00502520(void *);
extern void func_004A63F8(void);
extern void func_004A6490(void);
extern void func_004A66E8(void);
extern void func_004A6C78(void);

void func_004A62F8(void *object)
{
    State *state = (State *)((u32)D_00308068 + (u32)func_00506BB8() * 0x50);

    switch (state->phase) {
    case 0:
        if (!(u8)func_0049B418(&state->fade, 1.0f)) {
            state->phase = 1;
        }
        func_004A63F8();
        break;
    case 1:
        break;
    case 2:
        if (!(u8)func_0049B418(&state->fade, 0.0f)) {
            func_00502520(object);
        }
        func_004A63F8();
        break;
    }
    func_004A6490();
    if (state->changed) {
        func_004A66E8();
    }
    func_004A6C78();
}
