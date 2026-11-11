/* cflags: -G0 */
#include "common.h"

extern s32 func_0012E370(void);
extern s64 func_0012FEB0(s64, s64);
extern s32 D_003B175C[];

void func_L00_007106C0(void) {
    D_003B175C[0] = (s32)func_0012FEB0(func_0012E370(), 0x24000);
}
