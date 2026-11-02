#include "common.h"
extern int D_00171C28[];
int func_004FD500(void)
{
    int i;
    for (i = 1; i < 16; i++) {
        if (i == 3 || i == 9 || i == 12 || i == 15)
            continue;
        if ((D_00171C28[(i - 1) % 20] & 0x7FFF) != 0x7FFF)
            return 0;
    }
    return 1;
}
