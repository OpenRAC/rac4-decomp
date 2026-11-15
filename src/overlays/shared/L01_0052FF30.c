#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    u8 pad8[0x10];
} Rec;

extern s32 D_22FEA0[];
extern u8 D_003B41B0[];
extern Rec D_003B4230[];
extern s32 D_23F674[];

/* Point the object at D_22FEA0 at one table, then at the first of five 0x18-byte entries whose field is not below D_23F674. */
void func_L01_0052FF30(void) {
    s32 i;

    D_22FEA0[1] = (s32)D_003B41B0;
    for (i = 0; i < 5; i++) {
        if (D_003B4230[i].f4 >= D_23F674[0]) {
            D_22FEA0[2] = (s32)&D_003B4230[i];
            break;
        }
    }
}
