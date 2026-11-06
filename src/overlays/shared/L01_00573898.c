/* cflags: -O2 -G8 */
#include "common.h"
int func_L01_00573560();
int func_L01_005735A8();
int func_L01_00573688();
f32 func_L01_00573778();
f32 func_L01_005737C0();
int func_L01_00573808();
int func_L01_00573850();
unsigned int func_L01_00573898(unsigned char *p)
{
    if (p) {
        int x = p[17];
        if (x == 0) return (unsigned int)func_L01_00573560;
        if (x == 1) return (unsigned int)func_L01_005735A8;
        if (x == 2) return (unsigned int)func_L01_00573688;
        if (x == 3) return (unsigned int)func_L01_00573778;
        if (x == 4) return (unsigned int)func_L01_005737C0;
        if (x == 5) return (unsigned int)func_L01_00573808;
        if (x == 6) goto success;
    }
    return 0;
success:
    return (unsigned int)func_L01_00573850;
}
