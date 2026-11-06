#include "common.h"
typedef struct {
    char p0[0x1E];
    u8 f1E;
    u8 f1F;
} Type1;
extern Type1 D_00171BC0[];
extern s32 func_0045D348(void);

/* Advances the byte counters while the operation remains enabled. */
void func_00474058(void)
{
    if (func_0045D348()) {
        Type1 *p = D_00171BC0;
        if (p->f1E + 1 < 20) {
            s32 a;
            p->f1F++;
            a = p->f1E + 1;
            if (p->f1F >= (a >> 1)) {
                p->f1E = a;
                p->f1F = 0;
            }
        }
    }
}
