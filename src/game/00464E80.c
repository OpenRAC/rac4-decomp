#include "common.h"
typedef struct {
    int f0, f4, mode, fC, f10, f14;
} State;
extern State D_00171948[];
extern void func_00465F18(void), func_00464AF8(int);
void func_00464E80(void)
{
    func_00465F18();
    if (D_00171948[0].mode == 2) {
        if (D_00171948[0].f10 && !D_00171948[0].f14) {
            D_00171948[0].f10 = 0;
            func_00464AF8(7);
        }
        if (!D_00171948[0].f14)
            func_00464AF8(7);
        else {
            if (D_00171948[0].mode == 2 && D_00171948[0].f10)
                D_00171948[0].f10 = 0;
            func_00464AF8(11);
        }
    }
}
