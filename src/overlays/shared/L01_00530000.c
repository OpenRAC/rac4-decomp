#include "common.h"

extern s32 D_003B42B0[];
extern s32 D_003B4330[];
extern s32 D_22FEA0[];
extern s32 D_23F674[];

// Point the object at D_22FEA0 at two tables, the second only if its field is not below D_23F674.
void func_L01_00530000(void) {
    D_22FEA0[1] = (s32)D_003B42B0;
    if (D_003B4330[1] >= D_23F674[0]) {
        D_22FEA0[2] = (s32)D_003B4330;
    }
}
