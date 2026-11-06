#include "common.h"

typedef struct Obj Obj;
extern void func_00473A88(Obj *object, u8 state, s32 type);

void func_L01_004B8DC8(Obj *object, s64 selector)
{
    switch (selector) {
    case 0:
        func_00473A88(object, 7, -1);
        break;
    case 1:
        func_00473A88(object, 10, -1);
        break;
    case 2:
        func_00473A88(object, 3, 2);
        break;
    case 3:
        func_00473A88(object, 15, 1);
        break;
    }
}
