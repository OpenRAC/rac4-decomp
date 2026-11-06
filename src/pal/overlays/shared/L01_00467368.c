#include "common.h"

typedef struct SceneObject {
    u8 opaque[0xAC];
    u8 *state;
} SceneObject;
extern void func_L01_004672A8(SceneObject *object, s32 index);

void func_L01_00467368(SceneObject *object, s32 index)
{
    u8 *state = object->state;
    func_L01_004672A8(object, index);
    --state[4];
}
