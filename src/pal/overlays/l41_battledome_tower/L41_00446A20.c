#include "common.h"

typedef unsigned int Quadword __attribute__((mode(TI)));

typedef struct {
    s32 entries[16];
    s32 value40;
    f32 value44;
} L41SpawnState;

typedef struct {
    u8 unknown00[0x10];
    Quadword position;
    u8 unknown20[0x8C];
    L41SpawnState *state;
} L41SpawnObject;

extern L41SpawnObject *func_0046C1F0(s32 classId, s32 privateSize);
extern void func_0047C2F0(L41SpawnObject *object, const void *source);
extern void func_L41_00446E70(L41SpawnObject *object);

L41SpawnObject *func_L41_00446A20(Quadword position, s32 value)
{
    L41SpawnObject *object = func_0046C1F0(0x261E, 0x80);
    L41SpawnState *state;

    if (object != NULL) {
        state = object->state;
        func_0047C2F0(object, NULL);
        func_L41_00446E70(object);
        object->position = position;
        state->value40 = value;
        state->value44 = 26.0f / 3.0f;
    }
    return object;
}
