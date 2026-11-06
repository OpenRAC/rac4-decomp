#include "common.h"

typedef struct Obj Obj;
extern void func_00473A88(Obj *object, u8 state, s32 type);

void func_L01_004B92D0(Obj *object, s32 action)
{
    switch (action) {
    case 0:
        func_00473A88(object, 24, -1);
        break;
    case 1:
        func_00473A88(object, 28, -1);
        break;
    }
}
