#include "common.h"
extern int D_0021F198, D_0021EDD4, D_0021EDD8, D_0021DE10;
extern int D_00241B00[];
extern s8 D_0021F93A;
extern s8 D_0021F939;
extern s8 D_0021F938;
extern void func_00497980(int), func_004C74E0(int), func_00498CF8(void);
extern void func_0049B2F8(int, int);
extern const char *func_0045E038(int);
extern int func_00505B20(void);
extern void func_0049E790(int, const char *, void (*)(int), int, int, int, int, float);
void func_004C73E8(void)
{
    int s = D_0021F198;
    if (s != -1) {
        int id = func_00505B20();
        int state = 1;
        if (!D_0021EDD4 && D_0021EDD8 == 1)
            state = 21;
        if (D_0021DE10 == state && s < 8 && D_00241B00[0] == 1) {
            func_00497980(7);
            func_0049E790(4, func_0045E038(0x362E), func_004C74E0, 3, 0, 0, 0, -1.0f);
        } else {
            func_00498CF8();
            D_0021F93A = 0;
            D_0021F939 = 0;
            D_0021F938 = 0;
            func_0049B2F8(id, -1);
        }
    }
}
