#include "common.h"

typedef struct SceneObject SceneObject;
extern void func_L00_005F3FC8(SceneObject *object);

s32 func_L01_004FD730(SceneObject *object, u8 *context)
{
    func_L00_005F3FC8(object);
    context[0x97] = 0;
    return 1;
}
