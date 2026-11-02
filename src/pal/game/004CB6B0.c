#include "common.h"

extern s32 func_004CB780(void);
extern s32 D_0021EE3C;
extern s32 D_002213E0;
/* Start the operation and select its resulting state. */
void func_004CB6B0(void)
{
    s32 state;
    D_0021EE3C = 1;
    state = func_004CB780() ? 21 : 1;
    D_002213E0 = state;
}
