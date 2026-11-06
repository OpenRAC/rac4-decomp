#include "common.h"
int D_00220A20 = 0;
extern char *D_0023ACAC[];
extern int D_00221564;
extern void func_004E5D18(int), func_004E5EC8(void);
extern void func_004E5F98(void *, int, void *, int, void *, int);
void func_004F6440(void)
{
    func_004E5D18(D_00220A20);
    D_00221564 = 0;
    func_004E5F98(0, 0, 0, 0, D_0023ACAC[0] - 0x2C0000, 0x2C0000);
    func_004E5EC8();
}
