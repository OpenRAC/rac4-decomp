#include "common.h"

typedef struct { u8 pad[0x10]; s32 f10; u8 pad14[0x1E4 - 0x14]; s32 f1E4; } State;
extern void func_00464AF8(s32);
extern State D_00171948;
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
s32 D_0021F154 = 0;

/* Clears word 0x1E4 of D_00171948 when D_0021EDD4 and D_0021EDD8 are both 0, clears word 0x10, calls func_00464AF8(4) and sets D_0021F154 to 5. */
void func_00464C20(void) {
    if (D_0021EDD4 == 0 && D_0021EDD8 == 0) {
        D_00171948.f1E4 = 0;
    }
    D_00171948.f10 = 0;
    func_00464AF8(4);
    D_0021F154 = 5;
}
