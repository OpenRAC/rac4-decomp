#include "common.h"

extern int func_00506BB8(void);
extern char D_0030F820[];
extern void func_004A20D8(void *, float *, float *, float *, float *);
extern void func_0049CCF8(int, int, int, float, float, float, float);
/* Apply the selected table color and clear its update flag. */
void func_004CFD10(void)
{
    float a, b, c, d;
    int i = func_00506BB8();
    char *p = D_0030F820 + i * 0x103C;
    func_004A20D8(p + 0xF90, &a, &b, &c, &d);
    func_0049CCF8(i, 0, 0, a, b, c, d);
    *(int *)(p + 8) &= ~4;
}
