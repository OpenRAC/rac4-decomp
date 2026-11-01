#include "common.h"

typedef struct { u8 pad00[0xF8]; f32 angle; } Object;
extern Object *func_0046E100(s32 index);
extern f32 func_00454328(f32 angle, f32 delta);
extern void func_0046F008(Object *object);
extern void func_0046F6B8(Object *object);
extern void func_00470FD0(Object *object);

void func_0054E910(void)
{
    Object *object = func_0046E100(0);
    object->angle = func_00454328(object->angle, 0.02454369328916072845458984375f);
    func_0046F008(object);
    func_0046F6B8(object);
    func_00470FD0(object);
}
