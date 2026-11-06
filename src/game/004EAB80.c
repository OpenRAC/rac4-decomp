#include "common.h"
extern s32 D_00221E94;
typedef struct {
    char p0[8];
    s16 f8;
    s16 fA;
} Type1;
extern Type1 D_00327A60[];
/* Queues changed short selectors unless an update is already pending. */
void func_004EAB80(s32 a, s32 b)
{
    if (!D_00221E94) {
        if (D_00327A60[0].f8 != a || D_00327A60[0].fA != b) {
            D_00327A60[0].f8 = a;
            D_00327A60[0].fA = b;
            D_00221E94 = 45;
        }
    }
}
