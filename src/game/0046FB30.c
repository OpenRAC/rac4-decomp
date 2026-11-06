#include "common.h"
typedef struct {
    short f0, f2;
    unsigned char f4, f5;
    char pad[2];
} Entry;
extern Entry D_0026AFC0[];
extern int D_00221474, D_00221470;
void func_0046FB30(void)
{
    int i;
    D_0026AFC0[0].f2 = 512;
    D_0026AFC0[0].f5 = 255;
    D_00221474 = 1;
    D_00221470 = 0;
    D_0026AFC0[0].f4 = 0;
    D_0026AFC0[0].f0 = 0;
    for (i = 1; i < 31; i++) {
        D_0026AFC0[i].f5 = i + 1;
    }
    D_0026AFC0[i].f5 = 255;
}
