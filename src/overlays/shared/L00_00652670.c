/* Invoke the helper with zero if the observed byte flag is set, otherwise four. */
#include "common.h"

extern u8 D_0021E6F8;
s32 func_L00_006268E8(s32);

void func_L00_00652670(void) {
    func_L00_006268E8((D_0021E6F8 != 0) ? 0 : 4);
}
