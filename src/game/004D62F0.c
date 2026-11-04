#include "common.h"

extern int func_00505B20(void);
extern char D_0031D100[];
extern void func_004A13A0(void *, float *, float *, float *, float *);
extern void func_0049BFC0(int, int, int, float, float, float, float);
/* Apply the selected table color and clear its update flag. */
void func_004D62F0(void)
{
    float a, b, c, d;
    int i = func_00505B20();
    char *p = D_0031D100 + i * 0x528;
    func_004A13A0(p + 0x4BC, &a, &b, &c, &d);
    func_0049BFC0(i, 0, 0, a, b, c, d);
    *(int *)(p + 4) &= ~2;
}
