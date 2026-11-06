#include "common.h"

typedef struct {
    s32 state;
    f32 fade;
    u8 unknown8[0x48];
} State;

extern State D_003092A0[];
extern s32 func_00506BB8(void);
extern s32 func_0049B418(f32 *, f32);
extern void func_004AE890(void);
extern void func_004AE918(void);
extern void func_004AEAA0(void);
extern void func_00502520(void *);

void func_004AE7A8(void *object)
{
    State *state = &D_003092A0[func_00506BB8()];

    switch (state->state) {
    case 0:
        if (!(u8)func_0049B418(&state->fade, 1.0f)) {
            state->state = 1;
        }
        func_004AE890();
        break;
    case 1:
        break;
    case 2:
        if (!(u8)func_0049B418(&state->fade, 0.0f)) {
            func_00502520(object);
        }
        func_004AE890();
        break;
    }
    func_004AE918();
    func_004AEAA0();
}
