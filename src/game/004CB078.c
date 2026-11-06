#include "common.h"
extern unsigned char D_0021EE18;
int D_0021FA2C = 1;
extern int func_004E21D8(int, int, void *);
extern void func_004CA1D0(int, int);
void func_004CB078(int a)
{
    if (a) {
        if (D_0021EE18) {
            D_0021FA2C = 1;
            func_004E21D8(14, 0, 0);
            func_004CA1D0(2, 0);
        } else
            func_004CA1D0(15, 0);
    } else {
        func_004E21D8(12, 0, 0);
        func_004CA1D0(1, 0);
    }
}
