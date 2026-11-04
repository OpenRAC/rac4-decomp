#include "common.h"

extern void func_004493B0(void);
extern s32 D_00221228;
extern s32 D_002211F0;
extern s32 D_002211F4;
extern s32 D_00221324;
extern s32 D_00221E60;
extern s32 D_00221E64;
extern s32 D_00221E68;
extern s32 D_00221E6C;
u8 D_0021EB34 = 0;
u8 D_0021EB40 = 0;
u8 D_0021EB50 = 0;

/* Calls func_004493B0, then clears a set of state words and flag bytes. */
void func_00448720(void) {
    func_004493B0();
    D_00221228 = 0;
    D_002211F0 = 0;
    D_002211F4 = 0;
    D_0021EB34 = 0;
    D_0021EB40 = 0;
    D_0021EB50 = 0;
    D_00221324 = 0;
    D_00221E60 = 0;
    D_00221E64 = 0;
    D_00221E68 = 0;
    D_00221E6C = 0;
}
