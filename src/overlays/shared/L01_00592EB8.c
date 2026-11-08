#include "common.h"

typedef int u128_592EB8 __attribute__((mode(TI)));

extern void func_0046C978(void *, int, u128_592EB8 *);
extern int func_004742D8(void *, float, u128_592EB8, int, float, float, int, int, int);

/* from rac3-decomp's func_L01_004468C8 */
int func_L01_00592EB8(float x, float y, float z, void *object, int bone, int mode, int first, int second, int third)
{
    u128_592EB8 vector;
    func_0046C978(object, bone, &vector);
    return func_004742D8(object, x, vector, mode, y, z, first, second, third);
}
