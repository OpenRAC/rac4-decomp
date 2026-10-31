/* cflags: -O2 -G8 */
#include "common.h"
int func_L01_00576158();
int func_L01_005761A0();
int func_L01_00576280();
int func_L01_00576370();
int func_L01_005763B8();
int func_L01_00576400();
int func_L01_00576448();
unsigned int func_L01_00576490(unsigned char *p)
{
    if (p) {
        int x = p[17];
        if (x == 0) return (unsigned int)func_L01_00576158;
        if (x == 1) return (unsigned int)func_L01_005761A0;
        if (x == 2) return (unsigned int)func_L01_00576280;
        if (x == 3) return (unsigned int)func_L01_00576370;
        if (x == 4) return (unsigned int)func_L01_005763B8;
        if (x == 5) return (unsigned int)func_L01_00576400;
        if (x == 6) goto success;
    }
    return 0;
success:
    return (unsigned int)func_L01_00576448;
}
