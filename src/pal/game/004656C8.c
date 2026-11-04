#include "common.h"
typedef struct {
    int f0, f4, mode, fC, f10, f14;
} State;
extern State D_001719C8[];
extern void func_00466760(void), func_00465338(int);
void func_004656C8(void)
{
    func_00466760();
    if (D_001719C8[0].mode == 2) {
        if (D_001719C8[0].f10 && !D_001719C8[0].f14) {
            D_001719C8[0].f10 = 0;
            func_00465338(7);
        }
        if (!D_001719C8[0].f14)
            func_00465338(7);
        else {
            if (D_001719C8[0].mode == 2 && D_001719C8[0].f10)
                D_001719C8[0].f10 = 0;
            func_00465338(11);
        }
    }
}
