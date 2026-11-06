#include "common.h"

typedef struct Obj Obj;
extern void func_00473A88(Obj *object, u8 state, s32 type);

void func_L01_004B5238(Obj *object, s32 action)
{
    switch (action) {
    case 0:
        func_00473A88(object, 19, -1);
        break;
    case 1:
        func_00473A88(object, 21, -1);
        break;
    case 2:
        func_00473A88(object, 20, -1);
        break;
    }
}
