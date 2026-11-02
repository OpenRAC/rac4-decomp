#include "common.h"
typedef struct Type1 {
    char p[0x1C];
    unsigned int f1C;
} Type1;
extern Type1 D_0023F380[];
extern int D_002215D0;
extern s32 func_0048ADB0(void *, int, float);
/* Stop the active resource and reset its handle. */
void func_0045EA10(void)
{
    if (D_0023F380[0].f1C != 0xFFFFFFFFu) {
        func_0048ADB0(&D_002215D0, D_0023F380[0].f1C, 0.0f);
        D_0023F380[0].f1C = 0xFFFFFFFFu;
    }
}
