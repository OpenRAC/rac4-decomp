#include "common.h"
extern int D_0021F218, D_0021EE54, D_0021EE58, D_0021DE98;
extern int D_00241C00[];
extern void func_004985F0(int), func_004C81D0(int), func_0049BF40(int);
extern const char *func_0045E850(int);
extern int func_00506BB8(void);
extern void func_0049F4C8(int, const char *, void (*)(int), int, int, int, int, float);
void func_004C8108(void)
{
    if (D_0021F218 != -1) {
        int state = 1;
        if (!D_0021EE54 && D_0021EE58 == 1)
            state = 21;
        if (D_0021DE98 == state && D_0021F218 < 8 && D_00241C00[0] == 1) {
            func_004985F0(7);
            func_0049F4C8(4, func_0045E850(0x362E), func_004C81D0, 3, 0, 0, 0, -1.0f);
        } else
            func_0049BF40(func_00506BB8());
    }
}
