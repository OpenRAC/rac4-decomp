#include "common.h"

extern s32 D_00221100[2];
extern void (*D_00233910[][16])(s32);

/* from rac3-decomp's func_00382F00 */
void func_0043A470(s32 a) {
    s32 i;
    for (i = 0; i < D_00221100[a]; i++) D_00233910[a][i](a);
    D_00221100[a] = 0;
}
