#include "common.h"

typedef struct {
    s32 phase;
    u8 unknown4[4];
    u32 flags;
    u8 unknownC[0x12C];
    u8 list[0x6C];
} State;
extern State D_0031A960[];
extern u8 D_0021DEC1;
extern s32 D_00220A7C;
extern s32 func_00506BB8(void);
extern void func_00502520(void *);
extern void func_004D1BE8(void);
extern void func_004D1968(void);
extern void func_004D19A8(void);
extern void func_004D19E8(void);
extern s32 func_004A2468(void *);

void func_004D1340(void *object)
{
    State *state = (State *)((u32)D_0031A960 + (u32)func_00506BB8() * 0x1A4);

    switch (state->phase) {
    case 1:
        state->phase = 0;
        D_00220A7C = -(s32)D_0021DEC1;
        break;
    case 2:
        func_00502520(object);
        D_00220A7C = -(s32)D_0021DEC1;
        break;
    case 0:
        func_004D1BE8();
        break;
    }
    if (state->flags & 1) {
        func_004D1968();
    }
    if (state->flags & 2) {
        func_004D19A8();
    }
    func_004A2468(state->list);
    if (state->flags & 4) {
        func_004D19E8();
    }
}
