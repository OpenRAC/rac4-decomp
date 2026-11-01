#include "common.h"

typedef struct { u8 pad00[0xF8]; f32 angle; } Object;
extern Object *func_0046D820(s32 index);
extern f32 func_00453B10(f32 angle, f32 delta);
extern void func_0046E728(Object *object);
extern void func_0046EDD8(Object *object);
extern void func_004706F0(Object *object);

void func_0054D3A8(void)
{
    Object *object = func_0046D820(0);
    object->angle = func_00453B10(object->angle, 0.02454369328916072845458984375f);
    func_0046E728(object);
    func_0046EDD8(object);
    func_004706F0(object);
}
