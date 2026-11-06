#include "common.h"

extern s32 D_0021DE3C;

s32 func_00506BB8(void);
s32 func_00506B70(s32 arg0);
s32 func_00507C40(s32 arg0);
s32 func_005064A8(s32 arg0, f32 arg1);

void func_00431190(s32 arg0, f32 arg1)
{
    s32 index;
    s32 i;

    index = func_00506BB8();
    func_00506B70(arg0);
    if (func_00507C40(0x1D0000) == 0) {
        func_00506B70(index);
        return;
    }
    if (D_0021DE3C == 0) {
        for (i = 0; i < 0x14; i++) {
            if (arg1 <= 0.0f) {
                continue;
            }
            if (arg1 < 1.0f) {
                func_005064A8(0x1D0001 + i, arg1);
            }
        }
    }
    func_00506B70(index);
}
