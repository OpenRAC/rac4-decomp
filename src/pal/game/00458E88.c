#include "common.h"
extern void func_00131968(void), func_00138350(s32, s32, s32, s32);
extern s32 D_00171DB8[];
extern s32 D_0021DEF4;
void func_00458E88(void)
{
    s32 mode;
    func_00131968();
    mode = D_00171DB8[0];
    if (mode)
        D_0021DEF4 = 0;
    if (D_0021DEF4)
        func_00138350(0, 0, 80, 1);
    else
        func_00138350(0, 1, mode == 1 ? 3 : 2, 0);
}
