#include "common.h"

typedef struct SceneObject {
    u8 opaque[0xAC];
    u8 *state;
} SceneObject;
extern void func_L01_00465EF0(SceneObject *object, s32 index);

void func_L01_00465FB0(SceneObject *object, s32 index)
{
    u8 *state = object->state;
    func_L01_00465EF0(object, index);
    --state[4];
}
