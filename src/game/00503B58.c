#include "common.h"

typedef struct {
    u32 field00;
    u32 field04;
    u32 field08;
} State;

void func_00503B58(State *state, u32 value, u32 low, u32 high, u32 extra)
{
    state->field00 = value;
    state->field04 = low | high;
    state->field08 = extra;
}
