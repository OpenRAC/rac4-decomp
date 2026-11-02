#include "common.h"
/* Map the supported kind values to consecutive categories. */
int func_004C00E8(int a)
{
    int r = 0;
    switch (a) {
    case 1:
        break;
    case 2:
        r = 1;
        break;
    case 3:
        r = 2;
        break;
    case 4:
        r = 3;
        break;
    }
    return r;
}
