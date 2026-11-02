#include "common.h"
typedef struct { unsigned int f0, f4, f8, fc; } Entry;
typedef struct { int f0, f4; Entry *f8, *fc; int f10; } Context;
extern Context D_00235940[];
/* Relocate the table entries relative to its base. */
void func_00446988(void) {
    int i = 0;
    D_00235940[0].fc = D_00235940[0].f8;
    D_00235940[0].f10 = D_00235940[0].fc->f0 >> 4;
    if (D_00235940[0].f10 != 0) {
        do {
            D_00235940[0].fc[i].f0 += (unsigned int) D_00235940[0].fc;
            i++;
        } while (i < D_00235940[0].f10);
    }
}
