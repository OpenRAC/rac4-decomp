#include "common.h"
extern int D_0021F198, D_0021EDD4, D_0021EDD8, D_0021DE10;
extern int D_00241B00[];
extern void func_00497980(int), func_004C73A8(int), func_0049B208(int);
extern const char *func_0045E038(int);
extern int func_00505B20(void);
extern void func_0049E790(int, const char *, void (*)(int), int, int, int, int, float);
void func_004C72E0(void)
{
    if (D_0021F198 != -1) {
        int state = 1;
        if (!D_0021EDD4 && D_0021EDD8 == 1)
            state = 21;
        if (D_0021DE10 == state && D_0021F198 < 8 && D_00241B00[0] == 1) {
            func_00497980(7);
            func_0049E790(4, func_0045E038(0x362E), func_004C73A8, 3, 0, 0, 0, -1.0f);
        } else
            func_0049B208(func_00505B20());
    }
}
