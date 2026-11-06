#include "common.h"

typedef struct SceneObject SceneObject;
struct SceneObject {
    u8 opaque0[0x36];
    u16 flags;
    u8 opaque38[0x80];
    SceneObject *parent;
};
typedef struct ChildContext {
    u8 opaque0[0xD0];
    SceneObject *children[4];
} ChildContext;
extern void func_L01_005A8680(SceneObject *destination, const SceneObject *source);

void func_L01_004F59B0(SceneObject *object, ChildContext *context)
{
    SceneObject **child;
    s32 remaining;

    if ((object->parent->flags & 0xF800) == (object->flags & 0xF800))
        return;
    func_L01_005A8680(object, object->parent);
    child = context->children;
    for (remaining = 3; remaining >= 0; --remaining, ++child) {
        if (*child != NULL)
            func_L01_005A8680(*child, object->parent);
    }
}
