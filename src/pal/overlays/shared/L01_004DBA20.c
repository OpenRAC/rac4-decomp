#include "common.h"

typedef struct {
    u8 pad00[0x3C];
    f32 f3C;
    s32 f40;
} Type2;

typedef struct {
    u8 pad00[0x30];
    u8 f30;
    u8 pad31[0x7B];
    Type2 *fAC;
} Type1;

/* Reset the status byte and initialize the two fields in the attached state. */
void func_L01_004DBA20(Type1 *obj) {
    Type2 *state = obj->fAC;

    obj->f30 = 0xFF;
    state->f3C = -2.0f;
    state->f40 = -1;
}
