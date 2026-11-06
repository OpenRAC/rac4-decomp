#include "common.h"

extern s32 D_0021F218, D_0021EE54, D_0021EE58, D_0021DE98;
extern s32 D_00241C00[];
extern u8 D_0021F9DA, D_0021F9D9, D_0021F9D8;
extern s32 func_00506BB8(void);
extern void func_004985F0(s32);
extern const char *func_0045E850(s32);
extern void func_004C8308(s32);
extern void func_0049F4C8(s32, const char *, void (*)(s32), s32, s32, s32, s32, f32);
extern void func_00499A30(void);
extern void func_0049C030(s32, s32);
void func_004C8210(void)
{
    s32 selected = D_0021F218;
    if (selected != -1) {
        s32 index = func_00506BB8();
        s32 world = 1;
        if (!D_0021EE54)
            world = D_0021EE58 == 1 ? 21 : 1;
        if (D_0021DE98 == world && selected < 8 && D_00241C00[0] == 1) {
            func_004985F0(7);
            func_0049F4C8(4, func_0045E850(0x362E), func_004C8308, 3, 0, 0, 0, -1.0f);
            return;
        }
        func_00499A30();
        D_0021F9DA = 0;
        D_0021F9D9 = 0;
        D_0021F9D8 = 0;
        func_0049C030(index, -1);
    }
}
