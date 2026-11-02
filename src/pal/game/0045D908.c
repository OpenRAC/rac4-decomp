#include "common.h"
typedef struct {
    int f0, f4, f8, fC, f10, f14, f18;
    unsigned int f1C;
    short f20, f22, f24;
    unsigned char f26, f27;
} State;
extern State D_0023F380[];
extern short D_0023F3A8[];
void func_0045D908(void)
{
    D_0023F380[0].f0 = 0;
    D_0023F380[0].f4 = 0;
    D_0023F380[0].f8 = -1;
    D_0023F380[0].fC = -1;
    D_0023F380[0].f14 = -1;
    D_0023F380[0].f1C = 0xFFFFFFFFu;
    D_0023F380[0].f20 = 100;
    D_0023F380[0].f26 = 0;
    D_0023F380[0].f27 = 0;
    D_0023F380[0].f24 = 0;
    D_0023F380[0].f22 = 0;
    D_0023F3A8[0] = 0;
    D_0023F3A8[1] = 0;
    D_0023F3A8[2] = 0;
}
