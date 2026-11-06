#include "common.h"

typedef struct Obj Obj;
extern void func_00473A88(Obj *object, u8 state, s32 type);

void func_L01_00495050(Obj *object, s64 action)
{
    switch (action) {
    case 0:
        func_00473A88(object, 10, ((u8 *)object)[0x69] == 4 ? -1 : 4);
        break;
    case 1:
        func_00473A88(object, 13, ((u8 *)object)[0x69] == 4 ? -1 : 4);
        break;
    case 2:
        func_00473A88(object, 15, ((u8 *)object)[0x69] == 4 ? -1 : 4);
        break;
    }
}
