#include "common.h"

typedef struct { u8 pad[0x10]; s32 f10; u8 pad14[0x1E4 - 0x14]; s32 f1E4; } State;
extern void func_00464AF8(s32);
extern State D_00171948;
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
s32 D_0021F154 = 5;

/* Clears word 0x1E4 of D_00171948 when D_0021EDD4 and D_0021EDD8 are both 0, clears word 0x10, calls func_00464AF8(4) and sets D_0021F154 to 5. */
void func_00464C20(void) {
    if (D_0021EDD4 == 0 && D_0021EDD8 == 0) {
        D_00171948.f1E4 = 0;
    }
    D_00171948.f10 = 0;
    func_00464AF8(4);
    D_0021F154 = 5;
}

extern int D_0021EE54, D_0021EE58;
typedef struct Type1 {
    char p[8];
    s32 mode;
    u32 unknownC;
    int f10;
    char q[0x14];
    s32 threshold;
    char q2[0x198];
    int f1C4;
    int f1C8;
    int f1CC;
    int f1D0;
    s32 waiting;
    char r[0xC];
    int f1E4;
} Type1;
extern void func_00465338(int);

extern s32 D_0021DAE0;
extern s32 D_002213E4;
extern u8 D_002213E8;
extern void (*D_003D8038[])(void);

void func_00464B60(void)
{
    s32 value = (u32)D_0021F154 - 1;
    s32 index;

    D_0021F154 = value > -1 ? value : 0;
    if (((Type1 *)&D_00171948)[0].waiting ||
        (((Type1 *)&D_00171948)[0].mode == 2 && ((Type1 *)&D_00171948)[0].f10) ||
        ((Type1 *)&D_00171948)[0].threshold > 0) {
        D_002213E8 = 1;
    }
    index = D_0021DAE0;
    D_003D8038[index]();
    D_002213E4 = (u32)D_002213E4 + 1;
    if (D_0021DAE0 != index) {
        D_002213E4 = 0;
    }
}
