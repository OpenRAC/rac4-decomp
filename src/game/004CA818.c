#include "common.h"

extern s32 func_004CA8E8(void);
extern s32 D_0021EDBC;
extern s32 D_002212E0;
/* Start the operation and select its resulting state. */
void func_004CA818(void)
{
    s32 state;
    D_0021EDBC = 1;
    state = func_004CA8E8() ? 21 : 1;
    D_002212E0 = state;
}
