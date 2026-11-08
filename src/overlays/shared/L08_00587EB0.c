#include "common.h"

extern unsigned int D_002940C0[];
extern int func_L08_00587EF8(char *object, char *entry, float base);

/* from rac2-decomp's func_L09_0033E690 */
int func_L08_00587EB0(char *object, int index, float base)
{
    unsigned int entry;
    if (index == -1)
        return -1;
    entry = D_002940C0[index];
    if (entry == 0)
        return -1;
    return func_L08_00587EF8(object, (char *)entry, base);
}
