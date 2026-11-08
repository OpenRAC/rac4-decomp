#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern void func_0046D258(void *, int, u128 *);
extern int func_00474BB0(void *, float, u128, int, float, float, int, int, int);

/* PAL: from rac3-decomp's func_L01_004468C8 */
int func_L01_00597190(float x, float y, float z, void *object, int bone, int mode, int first, int second, int third)
{
    u128 vector;
    func_0046D258(object, bone, &vector);
    return func_00474BB0(object, x, vector, mode, y, z, first, second, third);
}
