#include "common.h"

typedef struct {
    u8 pad00[0x268];
    void *f268;
    u8 pad26C[0xD];
    u8 f279;
} Type1;

struct Context;
extern struct Context *D_00220DD4;
extern void func_L00_00745F80(void *, u8);

void func_L00_0071EA40(Type1 *object, s32 value)
{
    object->f279 = (u8)value;
    object->f268 = *(void **)((u8 *)D_00220DD4 + 0xB4);
    func_L00_00745F80(object->f268, object->f279);
}
