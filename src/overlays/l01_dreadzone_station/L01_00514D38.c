#include "common.h"

typedef struct Obj Obj;
extern void func_00473A88(Obj *object, u8 state, s32 type);

s32 func_L01_00514D38(Obj *object)
{
    if (((u8 *)object)[0x20] != 0)
        return 0;
    func_00473A88(object, 1, -1);
    return 1;
}
