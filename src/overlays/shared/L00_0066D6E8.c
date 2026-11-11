#include "common.h"
/* Ported from rac3-decomp's func_L01_004AB070 (src/levels/shared/L01_004AB040.c, GPL-3.0), the same code in both games. */

typedef struct { s32 id; s32 val; } E_4A7680;
extern E_4A7680 D_004EEE80[];
typedef struct { s16 id; s16 idx; s32 val; } O_4A7680;
void func_L00_0066D6E8(O_4A7680 *a0) {
    s32 i;
    for (i = 0; D_004EEE80[i].id != -1 && D_004EEE80[i].id != a0->id; i++) {
    }
    a0->idx = i;
    a0->val = D_004EEE80[i].val;
}
