#include "common.h"

typedef unsigned int Quadword __attribute__((mode(TI)));

typedef struct {
    s32 f00;
    f32 f04;
    s32 f08;
    u8 pad0C[4];
    Quadword f10;
} PrivateState;

extern void func_00474368(u8 *object, s32 state, s32 param);

void func_L01_004C85B8(u8 *object, const Quadword *position, const Quadword *direction, s32 field, f32 amount)
{
    PrivateState *state = *(PrivateState **)(object + 0xAC);

    *(Quadword *)(object + 0x10) = *position;
    state->f10 = *direction;
    state->f04 = amount;
    state->f00 = 0x53;
    state->f08 = field;
    *(u16 *)(object + 0x34) &= 0xFFF9;
    func_00474368(object, 3, -1);
}
