#include "common.h"
extern void func_00131968(void), func_00138350(s32, s32, s32, s32);
extern s32 D_00171D38[];
extern s32 D_0021DE6C;
void func_00458670(void)
{
    s32 mode;
    func_00131968();
    mode = D_00171D38[0];
    if (mode)
        D_0021DE6C = 0;
    if (D_0021DE6C)
        func_00138350(0, 0, 80, 1);
    else
        func_00138350(0, 1, mode == 1 ? 3 : 2, 0);
}
